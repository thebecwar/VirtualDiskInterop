// This is the main DLL file.

#include "stdafx.h"

// Uncomment to support Windows 10 functionality. Must retarget project to the appropriate SDK if you do.
//#define WIN10SUPPORT

// Enumerations
#include "Enumerations\ApplySnapshotVhdsetFlags.h"
#include "Enumerations\ApplySnapshotVhdsetVersions.h"
#include "Enumerations\AttachVirtualDiskFlags.h"
#include "Enumerations\AttachVirtualDiskVersions.h"
#include "Enumerations\CompactVirtualDiskFlags.h"
#include "Enumerations\CompactVirtualDiskVersions.h"
#include "Enumerations\CreateVirtualDiskFlags.h"
#include "Enumerations\CreateVirtualDiskVersions.h"
#include "Enumerations\DeleteSnapshotVhdsetFlags.h"
#include "Enumerations\DeleteSnapshotVhdsetVersions.h"
#include "Enumerations\DependentDiskFlags.h"
#include "Enumerations\DetachVirtualDiskFlags.h"
#include "Enumerations\ExpandVirtualDiskFlags.h"
#include "Enumerations\ExpandVirtualDiskVersions.h"
#include "Enumerations\GetStorageDependencyFlags.h"
#include "Enumerations\GetVirtualDiskInfoVersions.h"
#include "Enumerations\MergeVirtualDiskVersions.h"
#include "Enumerations\MergeVirtualDiskFlags.h"
#include "Enumerations\MirrorVirtualDiskFlags.h"
#include "Enumerations\MirrorVirtualDiskVersions.h"
#include "Enumerations\ModifyVhdsetFlags.h"
#include "Enumerations\ModifyVhdsetVersions.h"
#include "Enumerations\OpenVirtualDiskFlags.h"
#include "Enumerations\OpenVirtualDiskVersions.h"
#include "Enumerations\ResizeVirtualDiskFlags.h"
#include "Enumerations\ResizeVirtualDiskVersions.h"
#include "Enumerations\SetVirtualDiskInfoVersions.h"
#include "Enumerations\StorageDependencyInfoVersions.h"
#include "Enumerations\TakeSnapshotVhdsetFlags.h"
#include "Enumerations\TakeSnapshotVhdsetVersions.h"
#include "Enumerations\VirtualDiskAccessMasks.h"
#include "Enumerations\VirtualStorageDeviceTypes.h"

// Structures - Used by others
#include "Structures\VirtualStorageType.h"

// Other structures
#include "Structures\ApplySnapshotVhdsetParameters.h"
#include "Structures\AttachVirtualDiskParameters.h"
#include "Structures\CompactVirtualDiskParameters.h"
#include "Structures\CreateVirtualDiskParameters.h"
#include "Structures\DeleteSnapshotVhdsetParameters.h"
#include "Structures\ExpandVirtualDiskParameters.h"
#include "Structures\GetVirtualDiskInfo.h"
#include "Structures\MergeVirtualDiskParameters.h"
#include "Structures\MirrorVirtualDiskParameters.h"
#include "Structures\ModifyVhdsetParameters.h"
#include "Structures\OpenVirtualDiskParameters.h"
#include "Structures\QueryChangesVirtualDiskRange.h"
#include "Structures\ResizeVirtualDiskParameters.h"
#include "Structures\SetVirtualDiskInfo.h"
#include "Structures\StorageDependencyInfo.h"
#include "Structures\TakeSnapshotVhdsetParameters.h"
#include "Structures\VirtualDiskProgress.h"


// Wrapper class
#include "VirtualDiskInterop.h"