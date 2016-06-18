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
			VirtualDiskSafeHandle^ VirtualDiskHandle, 
			ApplySnapshotVhdsetParameters parameters, 
			ApplySnapshotVhdsetFlags flags)
		{
			return 0;
		}
#endif
		static unsigned int AddVirtualDiskParent(
			VirtualDiskSafeHandle^ VirtualDiskHandle, 
			String^ ParentPath)
		{
			return 0;
		}
		static unsigned int AttachVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle, 
			RawSecurityDescriptor^ SecurityDescriptor, 
			AttachVirtualDiskFlags Flags, 
			unsigned long ProviderSpecificFlags, 
			AttachVirtualDiskParameters Parameters, 
			Overlapped^ overlapped)
		{
			return 0;
		}
		static unsigned int BreakMirrorVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle)
		{
			return 0;
		}
		static unsigned int CompactVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			CompactVirtualDiskFlags Flags,
			CompactVirtualDiskParameters Parameters,
			Overlapped^ overlapped)
		{
			return 0;
		}
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
			DeleteSnapshotVhdsetFlags Flags)
		{
			return 0;
		}
#endif
		static unsigned int DeleteVirtualDiskMetadata(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			Guid Item)
		{
			return 0;
		}
		static unsigned int DetachVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			DetachVirtualDiskFlags Flags,
			unsigned long ProviderSpecificFlags)
		{
			return 0;
		}
		static unsigned int EnumerateVirtualDiskMetadata(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			unsigned long% NumberOfItems,
			array<Guid>^% Items) // This _will_ change
		{
			return 0;
		}
		static unsigned int ExpandVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			ExpandVirtualDiskFlags Flags,
			ExpandVirtualDiskParameters Parameters,
			Overlapped^ overlapped)
		{
			return 0;
		}
		static unsigned int GetStorageDependencyInformation(VirtualDiskSafeHandle^ VirtualDiskHandle) // TODO
		{
			return 0;
		}
		static unsigned int GetVirtualDiskInformation(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			GetVirtualDiskInfo% VirtualDiskInfo); // May change, but will look something like this
		
		static unsigned int GetVirtualDiskMetadata(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			Guid item,
			array<Byte>^% MetaData)
		{
			return 0;
		}
		static unsigned int GetVirtualDiskOperationProgress(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			Overlapped^ overlapped,
			VirtualDiskProgress% Progress)
		{
			return 0;
		}

		static unsigned int GetVirtualDiskPhysicalPath(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			String^% DiskPath);
		
		static unsigned int MergeVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			MergeVirtualDiskFlags Flags,
			MergeVirtualDiskParameters Parameters,
			Overlapped^ overlapped)
		{
			return 0;
		}
		static unsigned int MirrorVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			MirrorVirtualDiskFlags Flags,
			MirrorVirtualDiskParameters Parameters,
			Overlapped^ overlapped)
		{
			return 0;
		}
#ifdef WIN10SUPPORT
		static unsigned int ModifyVhdSet(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			ModifyVhdsetParameters Parameters,
			ModifyVhdsetFlags Flags)
		{
			return 0;
		}
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
			array<QueryChangesVirtualDiskRange>^ Ranges,
			unsigned long% RangeCount,
			unsigned long% ProcessedLength)
		{
			return 0;
		}
		static unsigned int ResizeVirtualDisk(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			ResizeVirtualDiskFlags Flags,
			ResizeVirtualDiskParameters Parameters,
			Overlapped^ overlapped)
		{
			return 0;
		}
		static unsigned int SetVirtualDiskInformation(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			SetVirtualDiskInfo VirtualDiskInfo)
		{
			return 0;
		}
		static unsigned int SetVirtualDiskMetadata(
			VirtualDiskSafeHandle^ VirtualDiskHandle,
			Guid Item,
			array<Byte>^ MetaData)
		{
			return 0;
		}
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
		private:
			static unsigned int m_BufferSize = 1024;
	};
}
