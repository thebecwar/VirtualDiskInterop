#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class GetVirtualDiskInfoSize
	{
	public:
		property unsigned long long VirtualSize
		{
			unsigned long long get()
			{
				return this->m_VirtualSize;
			}
			void set(unsigned long long value)
			{
				this->m_VirtualSize = value;
			}
		}
		property unsigned long long PhysicalSize
		{
			unsigned long long get()
			{
				return this->m_PhysicalSize;
			}
			void set(unsigned long long value)
			{
				this->m_PhysicalSize = value;
			}
		}
		property unsigned long BlockSize
		{
			unsigned long get()
			{
				return this->m_BlockSize;
			}
			void set(unsigned long value)
			{
				this->m_BlockSize = value;
			}
		}
		property unsigned long SectorSize
		{
			unsigned long get()
			{
				return this->m_SectorSize;
			}
			void set(unsigned long value)
			{
				this->m_SectorSize = value;
			}
		}
	private:
		unsigned long long m_VirtualSize;
		unsigned long long m_PhysicalSize;
		unsigned long m_BlockSize;
		unsigned long m_SectorSize;
	internal:
		void PopulateNativeStruct(GET_VIRTUAL_DISK_INFO* info)
		{
			info->Size.BlockSize = this->m_BlockSize;
			info->Size.PhysicalSize = this->m_PhysicalSize;
			info->Size.SectorSize = this->m_SectorSize;
			info->Size.VirtualSize = this->m_VirtualSize;
		}
		void ReadNativeStruct(GET_VIRTUAL_DISK_INFO* info)
		{
			this->m_VirtualSize = info->Size.VirtualSize;
			this->m_PhysicalSize = info->Size.PhysicalSize;
			this->m_BlockSize = info->Size.BlockSize;
			this->m_SectorSize = info->Size.SectorSize;
		}
	};

	public value class GetVirtualDiskInfoParentLocation
	{
	public:
		property bool ParentResolved
		{
			bool get()
			{
				return this->m_ParentResolved;
			}
			void set(bool value)
			{
				this->m_ParentResolved = value;
			}
		}
		property String^ ParentLocationBuffer
		{
			String^ get()
			{
				return this->m_ParentLocationBuffer;
			}
			void set(String^ value)
			{
				this->m_ParentLocationBuffer = value;
			}
		}
		property array<String^>^ ParentLocations
		{
			array<String^>^ get()
			{
				return this->m_ParentLocations;
			}
			void set(array<String^>^ value)
			{
				this->m_ParentLocations = value;
			}
		}
	private:
		bool m_ParentResolved;
		String^ m_ParentLocationBuffer;
		array<String^>^ m_ParentLocations;
	internal:
		size_t GetSizeNeeded()
		{
			if (this->m_ParentResolved)
			{ 
				// single string
				int cch = this->m_ParentLocationBuffer != nullptr ? this->m_ParentLocationBuffer->Length + 1 : 0;
				cch *= sizeof(Char);
				return cch;
			}
			else
			{
				if (this->m_ParentLocations != nullptr)
				{
					int cch = 0;
					for (int i = 0; i < this->m_ParentLocations->Length; i++)
					{
						cch += this->m_ParentLocations[i] != nullptr ? this->m_ParentLocations[i]->Length + 1 : 0;
					}
					cch = (cch + 2) * sizeof(Char);
					return cch;
				}
				else
				{
					return 0;
				}
			}
		}
		void PopulateNativeStruct(GET_VIRTUAL_DISK_INFO* info)
		{
			info->ParentLocation.ParentResolved = (BOOL)this->m_ParentResolved;
			if (this->m_ParentResolved)
			{
				int cbLen = (this->m_ParentLocationBuffer->Length + 1) * sizeof(Char);
				pin_ptr<const WCHAR> pString = PtrToStringChars(this->m_ParentLocationBuffer);
				memcpy_s(info->ParentLocation.ParentLocationBuffer, cbLen, pString, cbLen);
			}
		}
		void ReadNativeStruct(GET_VIRTUAL_DISK_INFO* info)
		{
			this->m_ParentResolved = info->ParentLocation.ParentResolved != 0;
			if (this->m_ParentResolved)
			{
				this->m_ParentLocationBuffer = gcnew String(info->ParentLocation.ParentLocationBuffer);
			}
			else
			{
				this->m_ParentLocations = Helpers::MultiSzToArray(info->ParentLocation.ParentLocationBuffer);
			}

		}
	};

	public value class GetVirtualDiskInfoPhysicalDisk
	{
	public:
		property unsigned long LogicalSectorSize
		{
			unsigned long get()
			{
				return this->m_LogicalSectorSize;
			}
			void set(unsigned long value)
			{
				this->m_LogicalSectorSize = value;
			}
		}
		property unsigned long PhysicalSectorSize
		{
			unsigned long get()
			{
				return this->m_PhysicalSectorSize;
			}
			void set(unsigned long value)
			{
				this->m_PhysicalSectorSize = value;
			}
		}
		property bool IsRemote
		{
			bool get()
			{
				return this->m_IsRemote;
			}
			void set(bool value)
			{
				this->m_IsRemote = value;
			}
		}
	private:
		unsigned long m_LogicalSectorSize;
		unsigned long m_PhysicalSectorSize;
		bool m_IsRemote;

	internal:
		void PopulateNativeStruct(GET_VIRTUAL_DISK_INFO* info)
		{
			info->PhysicalDisk.LogicalSectorSize = this->m_LogicalSectorSize;
			info->PhysicalDisk.PhysicalSectorSize = this->m_PhysicalSectorSize;
			info->PhysicalDisk.IsRemote = (BOOL)this->m_IsRemote;
		}
		void ReadNativeStruct(GET_VIRTUAL_DISK_INFO* info)
		{
			this->m_LogicalSectorSize = info->PhysicalDisk.LogicalSectorSize;
			this->m_PhysicalSectorSize = info->PhysicalDisk.PhysicalSectorSize;
			this->m_IsRemote = info->PhysicalDisk.IsRemote != 0;
		}
	};

#ifdef WIN10SUPPORT
	public value class GetVirtualDiskInfoChangeTrackingState
	{
	public:
		property bool Enabled
		{
			bool get()
			{
				return this->m_Enabled;
			}
			void set(bool value)
			{
				this->m_Enabled = value;
			}
		}
		property bool NewerChanges
		{
			bool get()
			{
				return this->m_NewerChanges;
			}
			void set(bool value)
			{
				this->m_NewerChanges = value;
			}
		}
		property String^ MostRecentId
		{
			String^ get()
			{
				return this->m_MostRecentId;
			}
			void set(String^ value)
			{
				this->m_MostRecentId = value;
			}
		}
	private:
		bool m_Enabled;
		bool m_NewerChanges;
		String^ m_MostRecentId;
	internal:
		size_t GetSizeNeeded()
		{
			int strLen = this->m_MostRecentId != nullptr ? this->m_MostRecentId->Length + 1 : 0;
			strLen *= sizeof(Char);
			return strLen + 8; // Add 2 BOOLs
		}
		void PopulateNativeStruct(GET_VIRTUAL_DISK_INFO* info)
		{
			info->ChangeTrackingState.Enabled = (BOOL)this->m_Enabled;
			info->ChangeTrackingState.NewerChanges = (BOOL)this->m_NewerChanges;
			if (!String::IsNullOrEmpty(this->m_MostRecentId))
			{
				int cbLen = (this->m_MostRecentId->Length + 1) * sizeof(Char);
				pin_ptr<const WCHAR> strPtr = PtrToStringChars(this->m_MostRecentId);
				memcpy_s(info->ChangeTrackingState.MostRecentId, cbLen, strPtr, cbLen);
			}
		}
		void ReadNativeStruct(GET_VIRTUAL_DISK_INFO* info)
		{
			this->m_Enabled = info->ChangeTrackingState.Enabled != 0;
			this->m_NewerChanges = info->ChangeTrackingState.Enabled != 0;
			this->m_MostRecentId = gcnew String(info->ChangeTrackingState.MostRecentId);
		}
	};
#endif

	public value class GetVirtualDiskInfo
	{
	public:
		property GetVirtualDiskInfoVersions Version
		{
			GetVirtualDiskInfoVersions get()
			{
				return this->m_Version;
			}
			void set(GetVirtualDiskInfoVersions value)
			{
				this->m_Version = value;
			}
		}
		property GetVirtualDiskInfoSize Size
		{
			GetVirtualDiskInfoSize get()
			{
				return this->m_Size;
			}
			void set(GetVirtualDiskInfoSize value)
			{
				this->m_Size = value;
			}
		}
		property Guid Identifier
		{
			Guid get()
			{
				return this->m_Identifier;
			}
			void set(Guid value)
			{
				this->m_Identifier = value;
			}
		}
		property GetVirtualDiskInfoParentLocation ParentLocation
		{
			GetVirtualDiskInfoParentLocation get()
			{
				return this->m_ParentLocation;
			}
			void set(GetVirtualDiskInfoParentLocation value)
			{
				this->m_ParentLocation = value;
			}
		}
		property Guid ParentIdentifier
		{
			Guid get()
			{
				return this->m_ParentIdentifier;
			}
			void set(Guid value)
			{
				this->m_ParentIdentifier = value;
			}
		}
		property unsigned long ParentTimestamp
		{
			unsigned long get()
			{
				return this->m_ParentTimestamp;
			}
			void set(unsigned long value)
			{
				this->m_ParentTimestamp = value;
			}
		}
		property VirtualDiskInterop::VirtualStorageType VirtualStorageType
		{
			VirtualDiskInterop::VirtualStorageType get()
			{
				return this->m_VirtualStorageType;
			}
			void set(VirtualDiskInterop::VirtualStorageType value)
			{
				this->m_VirtualStorageType = value;
			}
		}
		property unsigned long ProviderSubtype
		{
			unsigned long get()
			{
				return this->m_ProviderSubtype;
			}
			void set(unsigned long value)
			{
				this->m_ProviderSubtype = value;
			}
		}
		property bool Is4kAligned
		{
			bool get()
			{
				return this->m_Is4kAligned;
			}
			void set(bool value)
			{
				this->m_Is4kAligned = value;
			}
		}
		property bool IsLoaded
		{
			bool get()
			{
				return this->m_IsLoaded;
			}
			void set(bool value)
			{
				this->m_IsLoaded = value;
			}
		}
		property GetVirtualDiskInfoPhysicalDisk PhysicalDisk
		{
			GetVirtualDiskInfoPhysicalDisk get()
			{
				return this->m_PhysicalDisk;
			}
			void set(GetVirtualDiskInfoPhysicalDisk value)
			{
				this->m_PhysicalDisk = value;
			}
		}
		property unsigned long VhdPhysicalSectorSize
		{
			unsigned long get()
			{
				return this->m_VhdPhysicalSectorSize;
			}
			void set(unsigned long value)
			{
				this->m_VhdPhysicalSectorSize = value;
			}
		}
		property unsigned long long SmallestSafeVirtualSize
		{
			unsigned long long get()
			{
				return this->m_SmallestSafeVirtualSize;
			}
			void set(unsigned long long value)
			{
				this->m_SmallestSafeVirtualSize = value;
			}
		}
		property unsigned long FragmentationPercentage
		{
			unsigned long get()
			{
				return this->m_FragmentationPercentage;
			}
			void set(unsigned long value)
			{
				this->m_FragmentationPercentage = value;
			}
		}
		property Guid VirtualDiskId
		{
			Guid get()
			{
				return this->m_VirtualDiskId;
			}
			void set(Guid value)
			{
				this->m_VirtualDiskId = value;
			}
		}
#ifdef WIN10SUPPORT
		property GetVirtualDiskInfoChangeTrackingState ChangeTrackingState
		{
			GetVirtualDiskInfoChangeTrackingState get()
			{
				return this->m_ChangeTrackingState;
			}
			void set(GetVirtualDiskInfoChangeTrackingState value)
			{
				this->m_ChangeTrackingState = value;
			}
		}
#endif
	private:
		GetVirtualDiskInfoVersions m_Version;
		GetVirtualDiskInfoSize m_Size;
		Guid m_Identifier;
		GetVirtualDiskInfoParentLocation m_ParentLocation;
		Guid m_ParentIdentifier;
		unsigned long m_ParentTimestamp;
		VirtualDiskInterop::VirtualStorageType m_VirtualStorageType;
		unsigned long m_ProviderSubtype;
		bool m_Is4kAligned;
		bool m_IsLoaded;
		GetVirtualDiskInfoPhysicalDisk m_PhysicalDisk;
		unsigned long m_VhdPhysicalSectorSize;
		unsigned long long m_SmallestSafeVirtualSize;
		unsigned long m_FragmentationPercentage;
		Guid m_VirtualDiskId;
#ifdef WIN10SUPPORT
		GetVirtualDiskInfoChangeTrackingState m_ChangeTrackingState;
#endif;

	internal:
		GET_VIRTUAL_DISK_INFO* m_NativeData = NULL;
		GET_VIRTUAL_DISK_INFO* GetNative(size_t bufferSize)
		{
			if (this->m_NativeData != NULL)
			{
				LocalFree(this->m_NativeData);
				this->m_NativeData = NULL;
			}

			if (bufferSize < sizeof(GET_VIRTUAL_DISK_INFO))
			{
				return NULL;
				// TODO: Expand this to check buffers for ParentLocation and ChangeTrackingState.
			}

			this->m_NativeData = (GET_VIRTUAL_DISK_INFO*)LocalAlloc(LPTR, bufferSize);
			if (this->m_NativeData)
			{
				this->m_NativeData->Version = (GET_VIRTUAL_DISK_INFO_VERSION)this->m_Version;
				switch (this->m_Version)
				{
				case GetVirtualDiskInfoVersions::Size:
					this->m_Size.PopulateNativeStruct(this->m_NativeData);
					break;
				case GetVirtualDiskInfoVersions::Identifier:
					this->m_NativeData->Identifier = Helpers::ToGUID(this->m_Identifier);
					break;
				case GetVirtualDiskInfoVersions::ParentLocation:
					this->m_ParentLocation.PopulateNativeStruct(this->m_NativeData);
					break;
				case GetVirtualDiskInfoVersions::ParentIdentifier:
					this->m_NativeData->ParentIdentifier = Helpers::ToGUID(this->m_ParentIdentifier);
					break;
				case GetVirtualDiskInfoVersions::ParentTimestamp:
					this->m_NativeData->ParentTimestamp = this->m_ParentTimestamp;
					break;
				case GetVirtualDiskInfoVersions::VirtualStorageType:
					this->m_NativeData->VirtualStorageType.DeviceId = (ULONG)this->VirtualStorageType.DeviceId;
					this->m_NativeData->VirtualStorageType.VendorId = Helpers::ToGUID(this->VirtualStorageType.VendorId);
					break;
				case GetVirtualDiskInfoVersions::ProviderSubtype:
					this->m_NativeData->ProviderSubtype = this->m_ProviderSubtype;
					break;
				case GetVirtualDiskInfoVersions::Is4kAligned:
					this->m_NativeData->Is4kAligned = (BOOL)this->m_Is4kAligned;
					break;
				case GetVirtualDiskInfoVersions::IsLoaded:
					this->m_NativeData->IsLoaded = (BOOL)this->m_IsLoaded;
					break;
				case GetVirtualDiskInfoVersions::PhysicalDisk:
					this->m_PhysicalDisk.PopulateNativeStruct(this->m_NativeData);
					break;
				case GetVirtualDiskInfoVersions::VhdPhysicalSectorSize:
					this->m_NativeData->VhdPhysicalSectorSize = this->m_VhdPhysicalSectorSize;
					break;
				case GetVirtualDiskInfoVersions::SmallestSafeVirtualSize:
					this->m_NativeData->SmallestSafeVirtualSize = this->m_SmallestSafeVirtualSize;
					break;
				case GetVirtualDiskInfoVersions::Fragmentation:
					this->m_NativeData->FragmentationPercentage = this->m_FragmentationPercentage;
					break;
				case GetVirtualDiskInfoVersions::VirtualDiskID:
					this->m_NativeData->VirtualDiskId = Helpers::ToGUID(this->m_VirtualDiskId);
					break;
				}
			}
			return this->m_NativeData;
		}
		void ReleaseNative(bool updateData)
		{
			if (this->m_NativeData != NULL)
			{
				if (updateData)
				{
					switch ((GetVirtualDiskInfoVersions)this->m_NativeData->Version)
					{
					case GetVirtualDiskInfoVersions::Size:
						this->m_Size.ReadNativeStruct(this->m_NativeData);
						break;
					case GetVirtualDiskInfoVersions::Identifier:
						this->m_Identifier = Helpers::FromGUID(this->m_NativeData->Identifier);
						break;
					case GetVirtualDiskInfoVersions::ParentLocation:
						this->m_ParentLocation.ReadNativeStruct(this->m_NativeData);
						break;
					case GetVirtualDiskInfoVersions::ParentIdentifier:
						this->m_ParentIdentifier = Helpers::FromGUID(this->m_NativeData->ParentIdentifier);
						break;
					case GetVirtualDiskInfoVersions::ParentTimestamp:
						this->m_ParentTimestamp = this->m_NativeData->ParentTimestamp;
						break;
					case GetVirtualDiskInfoVersions::VirtualStorageType:
						this->m_VirtualStorageType = VirtualDiskInterop::VirtualStorageType();
						this->m_VirtualStorageType.DeviceId = (VirtualStorageDeviceTypes)this->m_NativeData->VirtualStorageType.DeviceId;
						this->m_VirtualStorageType.VendorId = Helpers::FromGUID(this->m_NativeData->VirtualStorageType.VendorId);
						break;
					case GetVirtualDiskInfoVersions::ProviderSubtype:
						this->m_ProviderSubtype = this->m_NativeData->ProviderSubtype;
						break;
					case GetVirtualDiskInfoVersions::Is4kAligned:
						this->m_Is4kAligned = this->m_NativeData->Is4kAligned != 0;
						break;
					case GetVirtualDiskInfoVersions::IsLoaded:
						this->m_IsLoaded = this->m_NativeData->IsLoaded != 0;
						break;
					case GetVirtualDiskInfoVersions::PhysicalDisk:
						this->m_PhysicalDisk.ReadNativeStruct(this->m_NativeData);
						break;
					case GetVirtualDiskInfoVersions::VhdPhysicalSectorSize:
						this->m_VhdPhysicalSectorSize = this->m_NativeData->VhdPhysicalSectorSize;
						break;
					case GetVirtualDiskInfoVersions::SmallestSafeVirtualSize:
						this->m_SmallestSafeVirtualSize = this->m_NativeData->SmallestSafeVirtualSize;
						break;
					case GetVirtualDiskInfoVersions::Fragmentation:
						this->m_FragmentationPercentage = this->m_NativeData->FragmentationPercentage;
						break;
					case GetVirtualDiskInfoVersions::VirtualDiskID:
						this->m_VirtualDiskId = Helpers::FromGUID(this->m_NativeData->VirtualDiskId);
						break;
					}
				}
				if (LocalFree(this->m_NativeData) == 0)
				{
					this->m_NativeData = NULL;
				}
			}
		}
	};
}