
Param ([switch] $Verbose)
function ServiceInformation
{
        param($servicename)
        write-host "`n"
        Write-Host $servicename "Details"
        Write-Host "---------------------------------------------" -ForegroundColor Blue
        Try
        {
            Get-Service $servicename -ErrorAction Stop
        }
        Catch
        {
            Write-Host $servicename "not found" -ForegroundColor Red
        }
}

write-host "`n"
Write-Host "Contrail Status For Windows"
Write-Host "---------------------------" -ForegroundColor Blue
Write-Host "---------------------------" -ForegroundColor Blue
if($Verbose)
{
    $osvalues = Get-WmiObject Win32_OperatingSystem
    Write-Host "System Details"
    Write-Host "--------------" -ForegroundColor Blue
    Write-Host "Computer Name:" $osvalues.CSName
    Write-Host "Build Number:" $osvalues.BuildNumber
    Write-Host "Build Version:" $osvalues.Version
    Write-Host "OS Name:" $osvalues.Caption
    Write-Host "OS Architecture:" $osvalues.OSArchitecture
    $val = [math]::round([int]$osvalues.FreeVirtualMemory/1MB,2)
    Write-Host "Free Virtual Memory:" $val "GB"
    $val = [math]::round([int]$osvalues.FreePhysicalMemory/1MB,2)
    Write-Host "Free Physical Memory:" $val "GB"
}

#Verify if Docker Daemon service is running or not:
ServiceInformation Docker
#Verify if contrail-cnm-plugin is running or not:
ServiceInformation contrail-cnm-plugin
#Verify if contrail-vrouter-nodemgr is running or not:
ServiceInformation contrail-vrouter-nodemgr
#Verify if contrail-vrouter-agent is running or not:
ServiceInformation contrail-vrouter-agent
write-host "`n"
Write-Host "VRouter"
Write-Host "------------" -ForegroundColor Blue
Try
{
    $vr = Get-VMSwitch Layered* | Get-VMSwitchExtension -Name vRouter* | Select-Object Name, Enabled, Running | Format-table -ErrorAction Stop
    if([string]::IsNullOrEmpty($vr))
    {
        write-host "VRouter name is empty or null" -ForegroundColor Red
        throw
    }
    else
    {
       $vr | Out-Host
    }
}
Catch
{
    Write-Host "Error Getting Extension" -ForegroundColor Red
}

if($Verbose)
{
    write-host "`n"
    Write-Host "Location of Contrail Components"
    Write-Host "-------------------------------" -ForegroundColor Blue
    Write-Host "-------------------------------" -ForegroundColor Blue
    Write-Host "Path to Binaries"
    Write-Host "-------------------------------" -ForegroundColor Blue
    Write-Host "Contrail Agent Binary and dependencies:" $ENV:Programfiles\Juniper Networks\Agent\
    Write-Host "Contrail windows CNM plugin:" $ENV:Programfiles\Juniper Networks\
    Write-Host "Contrail vrouter driver:" $ENV:Programfiles\Juniper Networks\vRouter\
    Write-Host "Contrail Utilities:" $ENV:Programfiles\Juniper Networks\vRouter utilities\
    Write-Host "-----------------------------------------------------------" -ForegroundColor Blue
    Write-Host "Path to Config and logs"
    Write-Host "-----------------------------------------------------------" -ForegroundColor Blue
    Write-Host "Default path to Contrail Agent Configuraton:" $ENV:ProgramData\contrail\etc\contrail\contrail-vrouter-agent.conf
    Write-Host "Default path to CNM Plugin Configuraton:" $ENV:ProgramData\contrail\etc\contrail\contrail-cnm-plugin.conf
    Write-Host "Default path to Node Manager Configuraton:" $ENV:ProgramData\contrail\etc\contrail\contrail-vrouter-nodemgr.conf
    Write-Host "Contrail Logs Directory:" $ENV:ProgramData\contrail\var\logs\contrail\
}