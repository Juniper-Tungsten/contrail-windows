#define _WIN32_DCOM

#include <iostream>
#include <comdef.h>
#include <Wbemidl.h>
#include <map>
#include "wmi.h"

#pragma comment(lib, "wbemuuid.lib")
using namespace std;

struct WMIException : public std::exception {
    const char * what() const throw () {
        return nullptr;
    }
};


int GetProcessorQueueLength()
{
    int len = -1;
    HRESULT hCOMOK=S_OK, hr= S_OK;

    IWbemLocator *pLoc = NULL;
    IWbemServices *pSvc = NULL;
    IEnumWbemClassObject* pEnumWbemClassObject = NULL;
    IWbemClassObject *pclsObj = NULL;

    ULONG uReturn = 0;
    VARIANT vtProp;

    VariantInit(&vtProp);

    try
    {

        hCOMOK = CoInitializeEx(0, COINIT_MULTITHREADED);
        if (FAILED(hCOMOK))
        {
            std::cout << "Failed to initialize COM library. Error code = 0x" << std::hex << hCOMOK << std::endl;
            throw WMIException();
        }

        hr = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);

        if (FAILED(hr))
        {
            std::cout << "Failed to initialize security. Error code = 0x"<< std::hex << hr << std::endl;
            throw WMIException();
        }


        hr = CoCreateInstance( CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *)&pLoc);

        if (FAILED(hr))
        {
            std::cout << "Failed to create IWbemLocator object."<< " Err code = 0x"<< std::hex << hr << std::endl;
            throw WMIException();
        }


        hr = pLoc->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), NULL, NULL, 0, NULL, 0, 0, &pSvc);

        if (FAILED(hr))
        {
            std::cout << "Could not connect. Error code = 0x" << std::hex << hr << std::endl;
            throw WMIException();
        }

        hr = CoSetProxyBlanket(pSvc,RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL, RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE );

        if (FAILED(hr))
        {
            std::cout << "Could not set proxy blanket. Error code = 0x" << std::hex << hr << std::endl;
            throw WMIException();
        }

        hr = pSvc->ExecQuery( bstr_t("WQL"), bstr_t("SELECT * FROM Win32_PerfFormattedData_PerfOS_System"), WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &pEnumWbemClassObject);

        if (FAILED(hr))
        {
            std::cout << "Query for operating system name failed." << " Error code = 0x" << std::hex << hr << std::endl;
            throw WMIException();
        }

        if (pEnumWbemClassObject)
        {
            hr = pEnumWbemClassObject->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

            if (FAILED(hr) || (0 == uReturn))
            {
                throw WMIException();
            }

            // Get the value of the Name property
            hr = pclsObj->Get(L"ProcessorQueueLength", 0, &vtProp, 0, 0);
            if (FAILED(hr) || (vtProp.vt != VT_I4))
            {
                throw WMIException();
            }
            //std::wcout << "ProcessorQueueLength" << vtProp.vt << std::endl<< vtProp.lVal << std::endl;
            len = vtProp.lVal;
        }
    }
    catch (WMIException &)
    {
        std::wcout << "WMI Exception";
    }

    if(pSvc)
    {
        pSvc->Release();
    }

    if (pLoc)
    {
        pLoc->Release();
    }

    if (pEnumWbemClassObject)
    {
        pEnumWbemClassObject->Release();
    }

    if (pclsObj)
    {
        pclsObj->Release();
    }

    VariantClear(&vtProp);

    if (SUCCEEDED(hCOMOK))
    {
        CoUninitialize();
    }

    return len;

}

