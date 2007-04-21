Attribute VB_Name = "Module1"
Public Const ezcaByte   As Byte = 0
Public Const ezcaString As Byte = 1
Public Const ezcaShort  As Byte = 2
Public Const ezcaLong   As Byte = 3
Public Const ezcaFloat  As Byte = 4
Public Const ezcaDouble As Byte = 5
Public Const EZCA_UNITS_SIZE As Byte = 8


Public Declare Function ezcaGet Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByVal ezcatype As Byte, _
    ByVal nelem As Long, _
    ByRef data As Any) As Long
    
Public Declare Function ezcaGetS Lib "ezca.dll" Alias "ezcaGet" _
   (ByVal pvname As String, _
    ByVal ezcatype As Byte, _
    ByVal nelem As Long, _
    ByVal data As String) As Long
   

Public Declare Function ezcaGetWithStatus Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByVal ezcatype As Byte, _
    ByVal nelem As Long, _
    ByRef data As Any, _
    ByRef timestamp As Long, _
    ByRef status As Integer, _
    ByRef severity As Integer) As Long

Public Declare Function ezcaPut Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByVal ezcatype As Byte, _
    ByVal nelem As Long, _
    ByRef data As Any) As Long

Public Declare Function ezcaPutString Lib "ezca.dll" Alias "ezcaPut" _
   (ByVal pvname As String, _
    ByVal ezcatype As Byte, _
    ByVal nelem As Long, _
    ByVal data As Any) As Long

Public Declare Function ezcaGetControlLimits Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByRef low As Double, _
    ByRef high As Double) As Long

Public Declare Function ezcaGetGraphicLimits Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByRef low As Double, _
    ByRef high As Double) As Long

Public Declare Function ezcaGetNelem Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByRef nelem As Long) As Long

Public Declare Function ezcaGetPrecision Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByRef precision As Integer) As Long

Public Declare Function ezcaGetStatus Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByRef timestamp As Long, _
    ByRef status As Integer, _
    ByRef severity As Integer) As Long

Public Declare Function ezcaGetUnits Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByVal units As String) As Long

Public Declare Sub ezcaAutoErrorMessageOff Lib "ezca.dll" ()

Public Declare Sub ezcaAutoErrorMessageOn Lib "ezca.dll" ()

Public Declare Function ezcaClearMonitor Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByVal ezcatype As Byte) As Long

Public Declare Sub ezcaDebugOff Lib "ezca.dll" ()

Public Declare Sub ezcaDebugOn Lib "ezca.dll" ()

Public Declare Function ezcaDelay Lib "ezca.dll" _
   (ByVal sec As Single) As Long

Public Declare Sub ezcaFree Lib "ezca.dll" _
   (ByRef buff As Any)

Public Declare Function ezcaGetRetryCount Lib "ezca.dll" () As Long

Public Declare Function ezcaGetTimeout Lib "ezca.dll" () As Single

Public Declare Function ezcaPvToChid Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByRef chid As Long) As Long

Public Declare Function ezcaSetMonitor Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByVal ezcatype As Byte) As Long

Public Declare Function ezcaSetRetryCount Lib "ezca.dll" _
   (ByVal retry As Long) As Long

Public Declare Function ezcaSetTimeout Lib "ezca.dll" _
   (ByVal sec As Single) As Long

Public Declare Function ezcaStartGroup Lib "ezca.dll" () As Long

Public Declare Sub ezcaTraceOff Lib "ezca.dll" ()

Public Declare Sub ezcaTraceOn Lib "ezca.dll" ()

Public Declare Function ezcaEndGroup Lib "ezca.dll" () As Long

Public Declare Function ezcaEndGroupWithReport Lib "ezca.dll" _
   (ByRef rcs As Long, _
    ByRef nrcs As Long) As Long

Public Declare Function ezcaGetErrorString Lib "ezca.dll" _
   (ByVal prefix As String, _
    ByVal buff As String) As Long

Public Declare Function ezcaNewMonitorValue Lib "ezca.dll" _
   (ByVal pvname As String, _
    ByVal ezcatype As Byte) As Long

Public Declare Sub ezcaPerror Lib "ezca.dll" _
   (ByVal prefix As String)
Public Declare Sub dummy1 Lib "ca.dll" ()
Public Declare Sub dummy2 Lib "com.dll" ()
  

Public Function ezcaGetString(pvname As String, nelem As Long, Value As String)

Dim status As Long
Dim temp As String
Dim pos As Long
temp = String(40, " ")
status = ezcaGetS(pvname, ezcaString, nelem, temp)
pos = InStr(1, temp, Chr(0))
Value = Mid(temp, 1, pos - 1)
ezcaGetString = status
End Function
