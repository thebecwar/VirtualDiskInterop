// VirtualDiskInterop.h

#pragma once

using namespace System;
using namespace System::Security::AccessControl;

namespace VirtualDiskInterop {

	public ref class VirtualDiskApi
	{
	public:
		static unsigned int AddVirtualDiskParent(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			String^ ParentPath);

#ifdef WIN10SUPPORT
		static unsigned int ApplySnapshotVhdSet(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			ApplySnapshotVhdsetParameters Parameters,
			ApplySnapshotVhdsetFlags Flags);
#endif

		static unsigned int AttachVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			RawSecurityDescriptor^ SecurityDescriptor,
			AttachVirtualDiskFlags Flags,
			unsigned long ProviderSpecificFlags,
			AttachVirtualDiskParameters Parameters,
			Overlapped^ overlapped);
		
		static unsigned int BreakMirrorVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle);

		static unsigned int CompactVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			CompactVirtualDiskFlags Flags,
			CompactVirtualDiskParameters Parameters,
			Overlapped^ overlapped);

		static unsigned int CreateVirtualDisk(
			VirtualDiskInterop::VirtualStorageType VirtualStorageType,
			String^ Path,
			VirtualDiskAccessMasks VirtualDiskAccessMask,
			RawSecurityDescriptor^ SecurityDescriptor,
			CreateVirtualDiskFlags Flags,
			unsigned long ProviderSpecificFlags,
			CreateVirtualDiskParameters Parameters,
			Overlapped^ overlapped,
			VirtualDiskSafeHandle^ VirtualDiskHandle);
		
#ifdef WIN10SUPPORT
		static unsigned int DeleteSnapshotVhdSet(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			DeleteSnapshotVhdsetParameters Parameters,
			DeleteSnapshotVhdsetFlags Flags);
#endif
		static unsigned int DeleteVirtualDiskMetadata(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			Guid Item);

		static unsigned int DetachVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			DetachVirtualDiskFlags Flags,
			unsigned long ProviderSpecificFlags);

		static unsigned int EnumerateVirtualDiskMetadata(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			[Out] array<Guid>^% Items);
		
		static unsigned int ExpandVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			ExpandVirtualDiskFlags Flags,
			ExpandVirtualDiskParameters Parameters,
			Overlapped^ overlapped);

		static unsigned int GetStorageDependencyInformation(
			IntPtr Handle,
			GetStorageDependencyFlags Flags,
			VirtualDiskInterop::StorageDependencyInfo% StorageDependencyInfo); // Note To Self: Don't change this from ref, User needs to set Version for call.
		static unsigned int GetStorageDependencyInformation(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			GetStorageDependencyFlags Flags,
			VirtualDiskInterop::StorageDependencyInfo% StorageDependencyInfo); // Note To Self: Don't change this from ref, User needs to set Version for call.
		
		static unsigned int GetVirtualDiskInformation(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			GetVirtualDiskInfo% VirtualDiskInfo); // Note To Self: Don't change this from ref, User needs to set Version for call.
		
		static unsigned int GetVirtualDiskMetadata(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			Guid item,
			[Out] array<Byte>^% MetaData);

		static unsigned int GetVirtualDiskOperationProgress(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			Overlapped^ overlapped,
			[Out] VirtualDiskProgress% Progress);

		static unsigned int GetVirtualDiskPhysicalPath(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			[Out] String^% DiskPath);
		
		static unsigned int MergeVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			MergeVirtualDiskFlags Flags,
			MergeVirtualDiskParameters Parameters,
			Overlapped^ overlapped);
		
		static unsigned int MirrorVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			MirrorVirtualDiskFlags Flags,
			MirrorVirtualDiskParameters Parameters,
			Overlapped^ overlapped);
		
#ifdef WIN10SUPPORT
		static unsigned int ModifyVhdSet(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			ModifyVhdsetParameters Parameters,
			ModifyVhdsetFlags Flags);
#endif

		static unsigned int OpenVirtualDisk(
			VirtualDiskInterop::VirtualStorageType VirtualStorageType,
			String^ Path,
			VirtualDiskAccessMasks VirtualDiskAccessMask,
			OpenVirtualDiskFlags Flags,
			OpenVirtualDiskParameters Parameters,
			VirtualDiskSafeHandle^ Handle);

		static unsigned int QueryChangesVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			String^ ChangeTrackingId,
			unsigned long long ByteOffset,
			unsigned long long ByteLength,
			/* QueryChangesVirtualDiskFlags Flags, */ // reserved parameter
			[Out] array<QueryChangesVirtualDiskRange>^% Ranges,
			[Out] unsigned long long% ProcessedLength);
		
		static unsigned int ResizeVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			ResizeVirtualDiskFlags Flags,
			ResizeVirtualDiskParameters Parameters,
			Overlapped^ overlapped);

		static unsigned int SetVirtualDiskInformation(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			SetVirtualDiskInfo VirtualDiskInfo);
		
		static unsigned int SetVirtualDiskMetadata(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			Guid Item,
			array<Byte>^ MetaData);

#ifdef WIN10SUPPORT
		static unsigned int TakeSnapshotVhdSet(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			TakeSnapshotVhdsetParameters Parameters,
			TakeSnapshotVhdsetFlags Flags)
		{
			return 0;
		}
#endif

		static property unsigned int BufferSize
		{
			unsigned int get()
			{
				return VirtualDiskApi::m_BufferSize;
			}
			void set(unsigned int value)
			{
				VirtualDiskApi::m_BufferSize = value;
			}
		}

		static property unsigned int StringBufferSize
		{
			unsigned int get()
			{
				return StorageDependencyInfo::StringBufferSize;
			}
			void set(unsigned int value)
			{
				StorageDependencyInfo::StringBufferSize = value;
			}
		}
		private:
			static unsigned int m_BufferSize = 1024;
	};
}
