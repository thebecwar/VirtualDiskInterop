// VirtualDiskInterop.h

#pragma once

using namespace System;
using namespace System::Security::AccessControl;

namespace VirtualDiskInterop {

	public ref class VirtualDiskApi
	{
	public:
#ifdef WIN10SUPPORT
		static unsigned int ApplySnapshotVhdSet(
			IntPtr VirtualDiskHandle, 
			ApplySnapshotVhdsetParameters parameters, 
			ApplySnapshotVhdsetFlags flags)
		{
			return 0;
		}
#endif
		static unsigned int AddVirtualDiskParent(
			IntPtr VirtualDiskHandle, 
			String^ ParentPath)
		{
			return 0;
		}
		static unsigned int AttachVirtualDisk(
			IntPtr VirtualDiskHandle, 
			RawSecurityDescriptor^ SecurityDescriptor, 
			AttachVirtualDiskFlags Flags, 
			unsigned long ProviderSpecificFlags, 
			AttachVirtualDiskParameters Parameters, 
			IntPtr Overlapped) // TODO: OVERLAPPED structure
		{
			return 0;
		}
		static unsigned int BreakMirrorVirtualDisk(
			IntPtr VirtualDiskHandle)
		{
			return 0;
		}
		static unsigned int CompactVirtualDisk(
			IntPtr VirtualDiskHandle,
			CompactVirtualDiskFlags Flags,
			CompactVirtualDiskParameters Parameters,
			IntPtr Overlapped)
		{
			return 0;
		}
		static unsigned int CreateVirtualDisk(
			_VirtualStorageType VirtualStorageType,
			String^ Path,
			VirtualDiskAccessMasks VirtualDiskAccessMask,
			RawSecurityDescriptor^ SecurityDescriptor,
			CreateVirtualDiskFlags Flags,
			unsigned long ProviderSpecificFlags,
			CreateVirtualDiskParameters Parameters,
			IntPtr Overlapped,
			IntPtr% VirtualDiskHandle)
		{
			return 0;
		}
#ifdef WIN10SUPPORT
		static unsigned int DeleteSnapshotVhdSet(
			IntPtr VirtualDiskHandle,
			DeleteSnapshotVhdsetParameters Parameters,
			DeleteSnapshotVhdsetFlags Flags)
		{
			return 0;
		}
#endif
		static unsigned int DeleteVirtualDiskMetadata(
			IntPtr VirtualDiskHandle,
			Guid Item)
		{
			return 0;
		}
		static unsigned int DetachVirtualDisk(
			IntPtr VirtualDiskHandle,
			DetachVirtualDiskFlags Flags,
			unsigned long ProviderSpecificFlags)
		{
			return 0;
		}
		static unsigned int EnumerateVirtualDiskMetadata(
			IntPtr VirtualDiskHandle,
			unsigned long% NumberOfItems,
			array<Guid>^% Items) // This _will_ change
		{
			return 0;
		}
		static unsigned int ExpandVirtualDisk(
			IntPtr VirtualDiskHandle,
			ExpandVirtualDiskFlags Flags,
			ExpandVirtualDiskParameters Parameters,
			IntPtr Overlapped)
		{
			return 0;
		}
		static unsigned int GetStorageDependencyInformation(IntPtr VirtualDiskHandle) // TODO
		{
			return 0;
		}
		static unsigned int GetVirtualDiskInformation(
			IntPtr VirtualDiskHandle,
			GetVirtualDiskInfo% VirtualDiskInfo) // May change, but will look something like this
		{
			return 0;
		}
		static unsigned int GetVirtualDiskMetadata(
			IntPtr VirtualDiskHandle,
			Guid item,
			array<Byte>^% MetaData)
		{
			return 0;
		}
		static unsigned int GetVirtualDiskOperationProgress(
			IntPtr VirtualDiskHandle,
			IntPtr Overlapped,
			VirtualDiskProgress% Progress)
		{
			return 0;
		}
		static unsigned int GetVirtualDiskPhysicalPath(
			IntPtr VirtualDiskHandle,
			String^% DiskPath)
		{
			return 0;
		}
		static unsigned int MergeVirtualDisk(
			IntPtr VirtualDiskHandle,
			MergeVirtualDiskFlags Flags,
			MergeVirtualDiskParameters Parameters,
			IntPtr Overlapped)
		{
			return 0;
		}
		static unsigned int MirrorVirtualDisk(
			IntPtr VirtualDiskHandle,
			MirrorVirtualDiskFlags Flags,
			MirrorVirtualDiskParameters Parameters,
			IntPtr Overlapped)
		{
			return 0;
		}
#ifdef WIN10SUPPORT
		static unsigned int ModifyVhdSet(
			IntPtr VirtualDiskHandle,
			ModifyVhdsetParameters Parameters,
			ModifyVhdsetFlags Flags)
		{
			DWORD result = ::ModifyVhdSet(NULL, NULL, (MODIFY_VHDSET_FLAG)0);
			return 0;
		}
#endif
		static unsigned int OpenVirtualDisk(
			_VirtualStorageType VirtualStorageType,
			String^ Path,
			VirtualDiskAccessMasks VirtualDiskAccessMask,
			OpenVirtualDiskFlags Flags,
			OpenVirtualDiskParameters Parameters,
			IntPtr% Handle)
		{
			return 0;
		}
		static unsigned int QueryChangesVirtualDisk(
			IntPtr VirtualDiskHandle,
			String^ ChangeTrackingId,
			unsigned long long ByteOffset,
			unsigned long long ByteLength,
			/* QueryChangesVirtualDiskFlags Flags, */ // reserved parameter
			array<QueryChangesVirtualDiskRange>^ Ranges,
			unsigned long% RangeCount,
			unsigned long% ProcessedLength)
		{
			return 0;
		}
		static unsigned int ResizeVirtualDisk(
			IntPtr VirtualDiskHandle,
			ResizeVirtualDiskFlags Flags,
			ResizeVirtualDiskParameters Parameters,
			IntPtr Overlapped)
		{
			return 0;
		}
		static unsigned int SetVirtualDiskInformation(
			IntPtr VirtualDiskHandle,
			SetVirtualDiskInfo VirtualDiskInfo)
		{
			return 0;
		}
		static unsigned int SetVirtualDiskMetadata(
			IntPtr VirtualDiskHandle,
			Guid Item,
			array<Byte>^ MetaData)
		{
			return 0;
		}
#ifdef WIN10SUPPORT
		static unsigned int TakeSnapshotVhdSet(
			IntPtr VirtualDiskHandle,
			TakeSnapshotVhdsetParameters Parameters,
			TakeSnapshotVhdsetFlags Flags)
		{
			return 0;
		}
#endif
	};
}
