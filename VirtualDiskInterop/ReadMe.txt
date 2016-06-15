Enumerations are defined in \Enumerations
Structures in \Structures

To interact with the API use the class VirtualDiskApi in the VirtualDiskInterop namespace.

To force compatibility with a specific windows version _WITHOUT_ retargeting to that version's SDK, define one 
of the following macros, either at the top of stdafx.h, or on the command line.

FORCE_WINDOWS_8_1
FORCE_WINDOWS_8
FORCE_WINDOWS_7

The version must be less than the SDK target. (ie - If the target SDK is Windows 7, Setting FORCE_WINDOWS_8 will break things. Don't do that.)