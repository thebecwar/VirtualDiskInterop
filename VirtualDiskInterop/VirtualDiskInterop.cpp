// This is the main DLL file.

#include "stdafx.h"

#include "Helpers.h"

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
#include "Enumerations\QueryChangesVirtualDiskFlags.h"
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

// Implementation Classes
#include "Structures\Overlapped.h"
#include "Structures\VirtualDiskSafeHandle.h"


// Wrapper class
#include "VirtualDiskInterop.h"

///////////////////////////////////////////////////////////
// Implementation of class members
//////////////////////////////////////////////////////////

namespace VirtualDiskInterop
{
	unsigned int VirtualDiskApi::CreateVirtualDisk(
		VirtualDiskInterop::VirtualStorageType VirtualStorageType,
		String^ Path,
		VirtualDiskAccessMasks VirtualDiskAccessMask,
		RawSecurityDescriptor^ SecurityDescriptor,
		CreateVirtualDiskFlags Flags,
		unsigned long ProviderSpecificFlags,
		CreateVirtualDiskParameters Parameters,
		Overlapped^ overlapped,
		VirtualDiskSafeHandle^ VirtualDiskHandle)
	{
		VIRTUAL_STORAGE_TYPE* storageType = VirtualStorageType.GetNative();
		pin_ptr<const WCHAR> pszPath = PtrToStringChars(Path);
		
		// TODO: Security Descriptor

		CREATE_VIRTUAL_DISK_PARAMETERS* parameters = Parameters.GetNative();
		
		HANDLE tmpHandle = INVALID_HANDLE_VALUE;

		unsigned int apiResult = ::CreateVirtualDisk(
			storageType,
			pszPath,
			(VIRTUAL_DISK_ACCESS_MASK)VirtualDiskAccessMask,
			NULL,
			(CREATE_VIRTUAL_DISK_FLAG)Flags,
			ProviderSpecificFlags,
			parameters,
			overlapped != nullptr ? overlapped->NativeOverlapped : NULL,
			&tmpHandle);

		VirtualStorageType.ReleaseNative(false);
		Parameters.ReleaseNative(false);

		VirtualDiskHandle->SetHandle(tmpHandle);
		
		return apiResult;
	}

	unsigned int VirtualDiskApi::GetVirtualDiskInformation(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		GetVirtualDiskInfo% VirtualDiskInfo)
	{

		GET_VIRTUAL_DISK_INFO* info = VirtualDiskInfo.GetNative(1024);

		HANDLE hDisk = VirtualDiskHandle->DangerousGetHandle().ToPointer();


		ULONG size = 1024;
		ULONG sizeUsed = 0;
		DWORD apiResult = ::GetVirtualDiskInformation(hDisk, &size, info, &sizeUsed);

		VirtualDiskInfo.ReleaseNative(true);

		return (unsigned int)apiResult;
	}

	unsigned int VirtualDiskApi::OpenVirtualDisk(
		VirtualDiskInterop::VirtualStorageType VirtualStorageType,
		String^ Path,
		VirtualDiskAccessMasks VirtualDiskAccessMask,
		OpenVirtualDiskFlags Flags,
		OpenVirtualDiskParameters Parameters,
		VirtualDiskSafeHandle^ Handle)
	{
		VIRTUAL_STORAGE_TYPE* storageType = VirtualStorageType.GetNative();
		pin_ptr<const wchar_t> szPath = PtrToStringChars(Path);

		OPEN_VIRTUAL_DISK_PARAMETERS* parameters = Parameters.GetNative();

		HANDLE tmpHandle = INVALID_HANDLE_VALUE;

		DWORD apiResult = ::OpenVirtualDisk(storageType,
			szPath,
			(VIRTUAL_DISK_ACCESS_MASK)VirtualDiskAccessMask,
			(OPEN_VIRTUAL_DISK_FLAG)Flags,
			parameters,
			&tmpHandle);

		Parameters.ReleaseNative(false);
		Handle->SetHandle(tmpHandle);

		return (unsigned int)apiResult;
	}

	

}