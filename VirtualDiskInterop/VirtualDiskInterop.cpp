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
#include "Enumerations\ProviderSpecificSubtypes.h"
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

#include <sddl.h>

///////////////////////////////////////////////////////////
// Implementation of class members
//////////////////////////////////////////////////////////

namespace VirtualDiskInterop
{
	unsigned int VirtualDiskApi::AddVirtualDiskParent(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		String^ ParentPath)
	{

		pin_ptr<const WCHAR> lpszPath = PtrToStringChars(ParentPath);
		unsigned int apiResult = ::AddVirtualDiskParent(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			lpszPath);

		return apiResult;
	}

#ifdef WIN10SUPPORT
	unsigned int VirtualDiskApi::ApplySnapshotVhdSet(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		ApplySnapshotVhdsetParameters Parameters,
		ApplySnapshotVhdsetFlags Flags)
	{
		APPLY_SNAPSHOT_VHDSET_PARAMETERS* parameters = Parameters.GetNative();

		unsigned int apiResult = ::ApplySnapshotVhdSet(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			parameters,
			(APPLY_SNAPSHOT_VHDSET_FLAG)Flags);

		Parameters.ReleaseNative(false);
		return apiResult;
	}
#endif

	unsigned int VirtualDiskApi::AttachVirtualDisk(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		RawSecurityDescriptor^ SecurityDescriptor,
		AttachVirtualDiskFlags Flags,
		unsigned long ProviderSpecificFlags,
		AttachVirtualDiskParameters Parameters,
		Overlapped^ overlapped)
	{
		PSECURITY_DESCRIPTOR securityDescriptor = NULL;
		if (SecurityDescriptor != nullptr)
		{
			array<Byte>^ rawSecurityDescriptorData = gcnew array<Byte>(SecurityDescriptor->BinaryLength);
			SecurityDescriptor->GetBinaryForm(rawSecurityDescriptorData, 0);
			pin_ptr<BYTE> ptr = &rawSecurityDescriptorData[0];
			securityDescriptor = (PSECURITY_DESCRIPTOR)ptr;
		}
		ATTACH_VIRTUAL_DISK_PARAMETERS* parameters = Parameters.GetNative();

		unsigned int apiResult = ::AttachVirtualDisk(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			securityDescriptor,
			(ATTACH_VIRTUAL_DISK_FLAG)Flags,
			(ULONG)ProviderSpecificFlags,
			parameters,
			overlapped != nullptr ? overlapped->NativeOverlapped : NULL);

		Parameters.ReleaseNative(false);
		return apiResult;
	}

	unsigned int VirtualDiskApi::BreakMirrorVirtualDisk(
		VirtualDiskSafeHandle^ VirtualDiskHandle)
	{
		return ::BreakMirrorVirtualDisk(VirtualDiskHandle->DangerousGetHandle().ToPointer());
	}

	unsigned int VirtualDiskApi::CompactVirtualDisk(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		CompactVirtualDiskFlags Flags,
		CompactVirtualDiskParameters Parameters,
		Overlapped^ overlapped)
	{
		COMPACT_VIRTUAL_DISK_PARAMETERS* parameters = Parameters.GetNative();

		unsigned int apiResult = ::CompactVirtualDisk(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			(COMPACT_VIRTUAL_DISK_FLAG)Flags,
			parameters,
			overlapped != nullptr ? overlapped->NativeOverlapped : NULL);

		Parameters.ReleaseNative(false);
		return apiResult;
	}

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
		PSECURITY_DESCRIPTOR securityDescriptor = NULL;
		if (SecurityDescriptor != nullptr)
		{
			array<Byte>^ rawSecurityDescriptorData = gcnew array<Byte>(SecurityDescriptor->BinaryLength);
			SecurityDescriptor->GetBinaryForm(rawSecurityDescriptorData, 0);
			pin_ptr<BYTE> ptr = &rawSecurityDescriptorData[0];
			securityDescriptor = (PSECURITY_DESCRIPTOR)ptr;
		}

		VIRTUAL_STORAGE_TYPE* storageType = VirtualStorageType.GetNative();
		pin_ptr<const WCHAR> pszPath = PtrToStringChars(Path);
		
		CREATE_VIRTUAL_DISK_PARAMETERS* parameters = Parameters.GetNative();
		
		HANDLE tmpHandle = INVALID_HANDLE_VALUE;

		unsigned int apiResult = ::CreateVirtualDisk(
			storageType,
			pszPath,
			(VIRTUAL_DISK_ACCESS_MASK)VirtualDiskAccessMask,
			securityDescriptor,
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

#ifdef WIN10SUPPORT
	unsigned int VirtualDiskApi::DeleteSnapshotVhdSet(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		DeleteSnapshotVhdsetParameters Parameters,
		DeleteSnapshotVhdsetFlags Flags)
	{
		DELETE_SNAPSHOT_VHDSET_PARAMETERS* parameters = Parameters.GetNative();

		unsigned int apiResult = ::DeleteSnapshotVhdSet(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			parameters,
			(DELETE_SNAPSHOT_VHDSET_FLAG)Flags);

		Parameters.ReleaseNative(false);
		return apiResult;
	}
#endif

	unsigned int VirtualDiskApi::DeleteVirtualDiskMetadata(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		Guid Item)
	{
		GUID itemGuid = Helpers::ToGUID(Item);
		return ::DeleteVirtualDiskMetadata(VirtualDiskHandle->DangerousGetHandle().ToPointer(), &itemGuid);
	}

	unsigned int VirtualDiskApi::DetachVirtualDisk(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		DetachVirtualDiskFlags Flags,
		unsigned long ProviderSpecificFlags)
	{

		unsigned int apiResult = ::DetachVirtualDisk(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			(DETACH_VIRTUAL_DISK_FLAG)Flags,
			ProviderSpecificFlags);

		return apiResult;
	}

	unsigned int VirtualDiskApi::EnumerateVirtualDiskMetadata(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		[Out] array<Guid>^% Items)
	{
		ULONG numberItems = 0;

		DWORD apiResult = ::EnumerateVirtualDiskMetadata(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			&numberItems,
			NULL);

		if ((apiResult == ERROR_INSUFFICIENT_BUFFER || apiResult == ERROR_MORE_DATA) && numberItems > 0)
		{
			GUID* raw = new GUID[numberItems];

			apiResult = ::EnumerateVirtualDiskMetadata(
				VirtualDiskHandle->DangerousGetHandle().ToPointer(),
				&numberItems,
				raw);

			if (apiResult == 0)
			{
				Items = gcnew array<Guid>(numberItems);
				for (ULONG i = 0; i < numberItems; i++)
				{
					Items[i] = Helpers::FromGUID(raw[i]);
				}
			}
			else
			{
				Items = gcnew array<Guid>(0);
			}
			delete raw;
		}
		else
		{
			Items = gcnew array<Guid>(0);
		}

		return apiResult;
	}

	unsigned int VirtualDiskApi::ExpandVirtualDisk(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		ExpandVirtualDiskFlags Flags,
		ExpandVirtualDiskParameters Parameters,
		Overlapped^ overlapped)
	{
		EXPAND_VIRTUAL_DISK_PARAMETERS* parameters = Parameters.GetNative();
		
		unsigned int apiResult = ::ExpandVirtualDisk(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			(EXPAND_VIRTUAL_DISK_FLAG)Flags,
			parameters,
			overlapped != nullptr ? overlapped->NativeOverlapped : NULL);

		Parameters.ReleaseNative(false);
		return apiResult;
	}

	unsigned int VirtualDiskApi::GetStorageDependencyInformation(
		IntPtr Handle,
		GetStorageDependencyFlags Flags,
		[Out] VirtualDiskInterop::StorageDependencyInfo% StorageDependencyInfo)
	{
		STORAGE_DEPENDENCY_INFO* info = StorageDependencyInfo.GetNative(VirtualDiskApi::BufferSize);

		ULONG sizeUsed = 0;
		unsigned int apiResult = ::GetStorageDependencyInformation(
			Handle.ToPointer(),
			(GET_STORAGE_DEPENDENCY_FLAG)Flags,
			(ULONG)VirtualDiskApi::BufferSize,
			info,
			&sizeUsed);

		StorageDependencyInfo.ReleaseNative(true);

		return apiResult;
	}
	unsigned int VirtualDiskApi::GetStorageDependencyInformation(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		GetStorageDependencyFlags Flags,
		[Out] VirtualDiskInterop::StorageDependencyInfo% StorageDependencyInfo)
	{
		return VirtualDiskApi::GetStorageDependencyInformation(VirtualDiskHandle->DangerousGetHandle(), Flags, StorageDependencyInfo);
	}

	unsigned int VirtualDiskApi::GetVirtualDiskInformation(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		GetVirtualDiskInfo% VirtualDiskInfo)
	{
		unsigned int bufferSize = VirtualDiskApi::m_BufferSize;
		GET_VIRTUAL_DISK_INFO* info = VirtualDiskInfo.GetNative(bufferSize);

		HANDLE hDisk = VirtualDiskHandle->DangerousGetHandle().ToPointer();

		ULONG size = bufferSize;
		ULONG sizeUsed = 0;
		DWORD apiResult = ::GetVirtualDiskInformation(hDisk, &size, info, &sizeUsed);

		VirtualDiskInfo.ReleaseNative(true);

		return (unsigned int)apiResult;
	}

	unsigned int VirtualDiskApi::GetVirtualDiskMetadata(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		Guid item,
		array<Byte>^% MetaData)
	{
		GUID itemGuid = Helpers::ToGUID(item);
		ULONG size = 0;
		unsigned int apiResult = ::GetVirtualDiskMetadata(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(), 
			&itemGuid, 
			&size, 
			NULL);
		
		if ((apiResult == ERROR_INSUFFICIENT_BUFFER || apiResult == ERROR_MORE_DATA) && size > 0)
		{
			PVOID raw = LocalAlloc(LPTR, size);
			apiResult = ::GetVirtualDiskMetadata(
				VirtualDiskHandle->DangerousGetHandle().ToPointer(),
				&itemGuid,
				&size,
				raw);

			if (apiResult == 0)
			{
				MetaData = gcnew array<Byte>(size);
				pin_ptr<Byte> pinnedResult = &MetaData[0];
				memcpy_s(pinnedResult, size, raw, size);
			}
			else
			{
				MetaData = gcnew array<Byte>(0);
			}
			LocalFree(raw);
		}
		else
		{
			MetaData = gcnew array<Byte>(0);
		}

		return apiResult;
	}

	unsigned int VirtualDiskApi::GetVirtualDiskOperationProgress(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		Overlapped^ overlapped,
		[Out] VirtualDiskProgress% Progress)
	{
		Progress = VirtualDiskProgress();
		VIRTUAL_DISK_PROGRESS* progresss = Progress.GetNative();
		
		unsigned int apiResult = ::GetVirtualDiskOperationProgress(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			overlapped != nullptr ? overlapped->NativeOverlapped : NULL,
			NULL);

		Progress.ReleaseNative(true);
		return apiResult;
	}

	unsigned int VirtualDiskApi::GetVirtualDiskPhysicalPath(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		String^% DiskPath)
	{
		WCHAR szPath[MAX_PATH];
		ULONG cbPathBuffer = sizeof(szPath);

		unsigned int apiResult = ::GetVirtualDiskPhysicalPath(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(), 
			&cbPathBuffer, 
			szPath);

		DiskPath = gcnew String(szPath);
		
		return apiResult;
	}

	unsigned int VirtualDiskApi::MergeVirtualDisk(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		MergeVirtualDiskFlags Flags,
		MergeVirtualDiskParameters Parameters,
		Overlapped^ overlapped)
	{
		MERGE_VIRTUAL_DISK_PARAMETERS* parameters = Parameters.GetNative();

		unsigned int apiResult = ::MergeVirtualDisk(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			(MERGE_VIRTUAL_DISK_FLAG)Flags,
			parameters,
			overlapped != nullptr ? overlapped->NativeOverlapped : NULL);

		Parameters.ReleaseNative(false);
		return apiResult;
	}

	unsigned int VirtualDiskApi::MirrorVirtualDisk(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		MirrorVirtualDiskFlags Flags,
		MirrorVirtualDiskParameters Parameters,
		Overlapped^ overlapped)
	{
		MIRROR_VIRTUAL_DISK_PARAMETERS* parameters = Parameters.GetNative();

		unsigned int apiResult = ::MirrorVirtualDisk(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			(MIRROR_VIRTUAL_DISK_FLAG)Flags,
			parameters,
			overlapped != nullptr ? overlapped->NativeOverlapped : NULL);

		Parameters.ReleaseNative(false);
		return apiResult;
	}

#ifdef WIN10SUPPORT
	unsigned int VirtualDiskApi::ModifyVhdSet(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		ModifyVhdsetParameters Parameters,
		ModifyVhdsetFlags Flags)
	{
		MODIFY_VHDSET_PARAMETERS* parameters = Parameters.GetNative();

		unsigned int apiResult = ::ModifyVhdSet(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			parameters,
			(MODIFY_VHDSET_FLAG)Flags);

		Parameters.ReleaseNative(false);
		return apiResult;
	}
#endif

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

	unsigned int VirtualDiskApi::QueryChangesVirtualDisk(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		String^ ChangeTrackingId,
		unsigned long long ByteOffset,
		unsigned long long ByteLength,
		/* QueryChangesVirtualDiskFlags Flags, */ // reserved parameter
		[Out] array<QueryChangesVirtualDiskRange>^% Ranges,
		[Out] unsigned long long% ProcessedLength)
	{
		QUERY_CHANGES_VIRTUAL_DISK_RANGE ranges[100];
		ULONG rangeCount = 100;

		pin_ptr<const WCHAR> trackingId = PtrToStringChars(ChangeTrackingId);
		ULONG64 processed = 0;

		unsigned int apiResult = ::QueryChangesVirtualDisk(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			trackingId,
			ByteOffset,
			ByteLength,
			QUERY_CHANGES_VIRTUAL_DISK_FLAG_NONE,
			ranges,
			&rangeCount,
			&processed);
		
		if (apiResult == 0 || apiResult == ERROR_MORE_DATA || apiResult == ERROR_INSUFFICIENT_BUFFER)
		{
			Ranges = gcnew array<QueryChangesVirtualDiskRange>(rangeCount);
			if (rangeCount > 0)
			{
				for (unsigned int i = 0; i < rangeCount; i++)
				{
					Ranges[i].ByteLength = ranges[i].ByteLength;
					Ranges[i].ByteOffset = ranges[i].ByteOffset;
					Ranges[i].Reserved = ranges[i].Reserved;
				}
			}
		}

		ProcessedLength = processed;

		return apiResult;
	}

	unsigned int VirtualDiskApi::ResizeVirtualDisk(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		ResizeVirtualDiskFlags Flags,
		ResizeVirtualDiskParameters Parameters,
		Overlapped^ overlapped)
	{
		RESIZE_VIRTUAL_DISK_PARAMETERS* parameters = Parameters.GetNative();

		unsigned int apiResult = ::ResizeVirtualDisk(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			(RESIZE_VIRTUAL_DISK_FLAG)Flags,
			parameters,
			overlapped != nullptr ? overlapped->NativeOverlapped : NULL);

		Parameters.ReleaseNative(false);

		return apiResult;
	}

	unsigned int VirtualDiskApi::SetVirtualDiskInformation(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		SetVirtualDiskInfo VirtualDiskInfo)
	{
		SET_VIRTUAL_DISK_INFO* info = VirtualDiskInfo.GetNative();

		unsigned int apiResult = ::SetVirtualDiskInformation(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			info);

		VirtualDiskInfo.ReleaseNative(false);
		return apiResult;
	}

	unsigned int VirtualDiskApi::SetVirtualDiskMetadata(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		Guid Item,
		array<Byte>^ MetaData)
	{

		GUID itemGuid = Helpers::ToGUID(Item);
		pin_ptr<Byte> rawData = &MetaData[0];

		unsigned int apiResult = ::SetVirtualDiskMetadata(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			&itemGuid,
			(ULONG)MetaData->Length,
			rawData);

		return apiResult;
	}

#ifdef WIN10SUPPORT
	unsigned int VirtualDiskApi::TakeSnapshotVhdSet(
		VirtualDiskSafeHandle^ VirtualDiskHandle,
		TakeSnapshotVhdsetParameters Parameters,
		TakeSnapshotVhdsetFlags Flags)
	{
		TAKE_SNAPSHOT_VHDSET_PARAMETERS* parameters = Parameters.GetNative();

		unsigned int apiResult = ::TakeSnapshotVhdSet(
			VirtualDiskHandle->DangerousGetHandle().ToPointer(),
			parameters,
			(TAKE_SNAPSHOT_VHDSET_FLAG)Flags);
		
		Parameters.ReleaseNative(false);
		return apiResult;
	}
#endif

}