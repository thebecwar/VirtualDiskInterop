#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class StorageDependencyInfoType1
	{
	public:
		property DependentDiskFlags DependencyTypeFlags
		{
			DependentDiskFlags get()
			{
				return this->m_DependencyTypeFlags;
			}
			void set(DependentDiskFlags value)
			{
				this->m_DependencyTypeFlags = value;
			}
		}
		property unsigned long ProviderSpecificFlags
		{
			unsigned long get()
			{
				return this->m_ProviderSpecificFlags;
			}
			void set(unsigned long value)
			{
				this->m_ProviderSpecificFlags = value;
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
	private:
		DependentDiskFlags m_DependencyTypeFlags;
		unsigned long m_ProviderSpecificFlags;
		VirtualDiskInterop::VirtualStorageType m_VirtualStorageType;
	internal:
		// Since this is returned as an array we need to accept a pointer to the array member
		void PopulateNativeStruct(STORAGE_DEPENDENCY_INFO_TYPE_1* info)
		{
			info->DependencyTypeFlags = (DEPENDENT_DISK_FLAG)this->m_DependencyTypeFlags;
			info->ProviderSpecificFlags = this->m_ProviderSpecificFlags;
			info->VirtualStorageType.DeviceId = (ULONG)this->m_VirtualStorageType.DeviceId;
			info->VirtualStorageType.VendorId = Helpers::ToGUID(this->m_VirtualStorageType.VendorId);
		}
		void ReadNativeStruct(STORAGE_DEPENDENCY_INFO_TYPE_1* info)
		{
			this->m_DependencyTypeFlags = (DependentDiskFlags)info->DependencyTypeFlags;
			this->m_ProviderSpecificFlags = info->ProviderSpecificFlags;
			this->m_VirtualStorageType.DeviceId = (VirtualStorageDeviceTypes)info->VirtualStorageType.DeviceId;
			this->m_VirtualStorageType.VendorId = Helpers::FromGUID(info->VirtualStorageType.VendorId);
		}
		StorageDependencyInfoType1(STORAGE_DEPENDENCY_INFO_TYPE_1* info)
		{
			this->ReadNativeStruct(info);
		}
	};

	public value class StorageDependencyInfoType2
	{
	public:
		property DependentDiskFlags DependencyTypeFlags
		{
			DependentDiskFlags get()
			{
				return this->m_DependencyTypeFlags;
			}
			void set(DependentDiskFlags value)
			{
				this->m_DependencyTypeFlags = value;
			}
		}
		property unsigned long ProviderSpecificFlags
		{
			unsigned long get()
			{
				return this->m_ProviderSpecificFlags;
			}
			void set(unsigned long value)
			{
				this->m_ProviderSpecificFlags = value;
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
		property unsigned long AncestorLevel
		{
			unsigned long get()
			{
				return this->m_AncestorLevel;
			}
			void set(unsigned long value)
			{
				this->m_AncestorLevel = value;
			}
		}
		property String^ DependencyDeviceName
		{
			String^ get()
			{
				return this->m_DependencyDeviceName;
			}
			void set(String^ value)
			{
				this->m_DependencyDeviceName = value;
			}
		}
		property String^ HostVolumeName
		{
			String^ get()
			{
				return this->m_HostVolumeName;
			}
			void set(String^ value)
			{
				this->m_HostVolumeName = value;
			}
		}
		property String^ DependentVolumeName
		{
			String^ get()
			{
				return this->m_DependentVolumeName;
			}
			void set(String^ value)
			{
				this->m_DependentVolumeName = value;
			}
		}
		property String^ DependentVolumeRelativePath 
		{
			String^ get()
			{
				return this->m_DependentVolumeRelativePath;
			}
			void set(String^ value)
			{
				this->m_DependentVolumeRelativePath = value;
			}
		}
	private:
		DependentDiskFlags m_DependencyTypeFlags;
		unsigned long m_ProviderSpecificFlags;
		VirtualDiskInterop::VirtualStorageType m_VirtualStorageType;
		unsigned long m_AncestorLevel;
		String^ m_DependencyDeviceName;
		String^ m_HostVolumeName;
		String^ m_DependentVolumeName;
		String^ m_DependentVolumeRelativePath;

		static unsigned int m_StringBufferSize = MAX_PATH * 2;
	internal:
		static property unsigned int StringBufferSize
		{
			unsigned int get()
			{
				return StorageDependencyInfoType2::m_StringBufferSize;
			}
			void set(unsigned int value)
			{
				StorageDependencyInfoType2::m_StringBufferSize = value;
			}
		}
		
		LPWSTR m_NativeDependencyDeviceName = NULL;
		LPWSTR m_NativeHostVolumeName = NULL;
		LPWSTR m_NativeDependentVolumeName = NULL;
		LPWSTR m_NativeDependentVolumeRelativePath = NULL;

		// Since this is returned as an array we need to accept a pointer to the array member
		void PopulateNativeStruct(STORAGE_DEPENDENCY_INFO_TYPE_2* info)
		{
			this->ReleaseNativeData();

			info->DependencyTypeFlags = (DEPENDENT_DISK_FLAG)this->m_DependencyTypeFlags;
			info->ProviderSpecificFlags = this->m_ProviderSpecificFlags;
			info->VirtualStorageType.DeviceId = (ULONG)this->m_VirtualStorageType.DeviceId;
			info->VirtualStorageType.VendorId = Helpers::ToGUID(this->m_VirtualStorageType.VendorId);
			info->AncestorLevel = this->m_AncestorLevel;
			
			if (!String::IsNullOrEmpty(this->m_DependencyDeviceName))
			{
				this->m_NativeDependencyDeviceName = Helpers::AllocString(this->m_DependencyDeviceName);
			}
			else
			{
				this->m_NativeDependencyDeviceName = (LPWSTR)LocalAlloc(LPTR, StorageDependencyInfoType2::m_StringBufferSize);
			}
			info->DependencyDeviceName = this->m_NativeDependencyDeviceName;

			if (!String::IsNullOrEmpty(this->m_HostVolumeName))
			{
				this->m_NativeHostVolumeName = Helpers::AllocString(this->m_HostVolumeName);
			}
			else
			{
				this->m_NativeHostVolumeName = (LPWSTR)LocalAlloc(LPTR, StorageDependencyInfoType2::m_StringBufferSize);
			}
			info->HostVolumeName = this->m_NativeHostVolumeName;

			if (!String::IsNullOrEmpty(this->m_DependentVolumeName))
			{
				this->m_NativeDependentVolumeName = Helpers::AllocString(this->m_DependentVolumeName);
			}
			else
			{
				this->m_NativeDependentVolumeName = (LPWSTR)LocalAlloc(LPTR, StorageDependencyInfoType2::m_StringBufferSize);
			}
			info->DependentVolumeName = this->m_NativeDependentVolumeName;

			if (!String::IsNullOrEmpty(this->m_DependentVolumeRelativePath))
			{
				this->m_NativeDependentVolumeRelativePath = Helpers::AllocString(this->m_DependentVolumeRelativePath);
			}
			else
			{
				this->m_NativeDependentVolumeRelativePath = (LPWSTR)LocalAlloc(LPTR, StorageDependencyInfoType2::m_StringBufferSize);
			}
			info->DependentVolumeRelativePath = this->m_NativeDependentVolumeRelativePath;
		}
		void ReadNativeStruct(STORAGE_DEPENDENCY_INFO_TYPE_2* info)
		{
			this->m_DependencyTypeFlags = (DependentDiskFlags)info->DependencyTypeFlags;
			this->m_ProviderSpecificFlags = info->ProviderSpecificFlags;
			this->m_VirtualStorageType.DeviceId = (VirtualStorageDeviceTypes)info->VirtualStorageType.DeviceId;
			this->m_VirtualStorageType.VendorId = Helpers::FromGUID(info->VirtualStorageType.VendorId);
			this->m_DependencyDeviceName = gcnew String(info->DependencyDeviceName);
			this->m_HostVolumeName = gcnew String(info->HostVolumeName);
			this->m_DependentVolumeName = gcnew String(info->DependentVolumeName);
			this->m_DependentVolumeRelativePath = gcnew String(info->DependentVolumeRelativePath);

			this->ReleaseNativeData();
		}
		StorageDependencyInfoType2(STORAGE_DEPENDENCY_INFO_TYPE_2* info)
		{
			this->ReadNativeStruct(info);
		}
		void ReleaseNativeData()
		{
			if (this->m_NativeDependencyDeviceName)
			{
				LocalFree(this->m_NativeDependencyDeviceName);
				this->m_NativeDependencyDeviceName = NULL;
			}
			if (this->m_NativeHostVolumeName)
			{
				LocalFree(this->m_NativeHostVolumeName);
				this->m_NativeHostVolumeName = NULL;
			}
			if (this->m_NativeDependentVolumeName)
			{
				LocalFree(this->m_NativeDependentVolumeName);
				this->m_NativeDependentVolumeName = NULL;
			}
			if (this->m_NativeDependentVolumeRelativePath)
			{
				LocalFree(this->m_NativeDependentVolumeRelativePath);
				this->m_NativeDependentVolumeRelativePath = NULL;
			}
		}
	};

	public value class StorageDependencyInfo
	{
	public:
		property StorageDependencyInfoVersions Version
		{
			StorageDependencyInfoVersions get()
			{
				return this->m_Version;
			}
			void set(StorageDependencyInfoVersions value)
			{
				this->m_Version = value;
			}
		}
		property unsigned long NumberEntries
		{
			unsigned long get()
			{
				return this->m_NumberEntries;
			}
			void set(unsigned long value)
			{
				this->m_NumberEntries = value;
			}
		}
		property array<StorageDependencyInfoType1>^ Version1Entries
		{
			array<StorageDependencyInfoType1>^ get()
			{
				return this->m_Version1Entries;
			}
			void set(array<StorageDependencyInfoType1>^ value)
			{
				this->m_Version1Entries = value;
			}
		}
		property array<StorageDependencyInfoType2>^ Version2Entries
		{
			array<StorageDependencyInfoType2>^ get()
			{
				return this->m_Version2Entries;
			}
			void set(array<StorageDependencyInfoType2>^ value)
			{
				this->m_Version2Entries = value;
			}
		}
		static property unsigned int StringBufferSize
		{
			unsigned int get()
			{
				return StorageDependencyInfoType2::StringBufferSize;
			}
			void set(unsigned int value)
			{
				StorageDependencyInfoType2::StringBufferSize = value;
			}
		}
	private:
		StorageDependencyInfoVersions m_Version;
		unsigned long m_NumberEntries;
		array<StorageDependencyInfoType1>^ m_Version1Entries;
		array<StorageDependencyInfoType2>^ m_Version2Entries;

	internal:
		STORAGE_DEPENDENCY_INFO* m_NativeData;
		STORAGE_DEPENDENCY_INFO* GetNative(unsigned int bufferSize)
		{
			this->m_NativeData = (STORAGE_DEPENDENCY_INFO*)LocalAlloc(LPTR, bufferSize);
			this->m_NativeData->Version = (STORAGE_DEPENDENCY_INFO_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case StorageDependencyInfoVersions::Version1:
				if (this->m_Version1Entries != nullptr && this->m_Version1Entries->Length > 0)
				{
					this->m_NativeData->NumberEntries = this->m_Version1Entries->Length;
					for (unsigned int i = 0; i < this->m_NativeData->NumberEntries; i++)
					{
						this->m_Version1Entries[i].PopulateNativeStruct(&this->m_NativeData->Version1Entries[i]);
					}
				}
				else
				{
					this->m_NativeData->NumberEntries = 0;
				}
				break;
			case StorageDependencyInfoVersions::Version2:
				if (this->m_Version2Entries != nullptr && this->m_Version2Entries->Length > 0)
				{
					this->m_NativeData->NumberEntries = this->m_Version2Entries->Length;
					for (int i = 0; i < this->m_Version2Entries->Length; i++)
					{
						this->m_Version2Entries[i].PopulateNativeStruct(&this->m_NativeData->Version2Entries[i]);
					}
				}
				else
				{
					this->m_NativeData->NumberEntries = 0;
				}
			}
			return this->m_NativeData;
		}
		void ReleaseNative(bool updateData)
		{
			if (this->m_NativeData)
			{
				if (updateData)
				{
					this->m_Version = (StorageDependencyInfoVersions)this->m_NativeData->Version;
					this->m_NumberEntries = this->m_NativeData->NumberEntries;
					switch (this->m_Version)
					{
					case StorageDependencyInfoVersions::Version1:
						this->m_Version1Entries = gcnew array<StorageDependencyInfoType1>(this->m_NumberEntries);
						if (this->m_NumberEntries > 0)
						{
							for (unsigned int i = 0; i < this->m_NumberEntries; i++)
							{
								this->m_Version1Entries[i].ReadNativeStruct(&this->m_NativeData->Version1Entries[i]);
							}
						}
						if (this->m_Version2Entries != nullptr && this->m_Version2Entries->Length > 0)
						{
							for (int i = 0; i < this->m_Version2Entries->Length; i++)
							{
								this->m_Version2Entries[i].ReleaseNativeData();
							}
						}
						break;
					case StorageDependencyInfoVersions::Version2:
						this->m_Version2Entries = gcnew array<StorageDependencyInfoType2>(this->m_NumberEntries);
						if (this->m_NumberEntries > 0)
						{
							for (unsigned int i = 0; i < this->m_NumberEntries; i++)
							{
								this->m_Version2Entries[i].ReadNativeStruct(&this->m_NativeData->Version2Entries[i]);
							}
						}
						break;
					}
				}
				LocalFree(this->m_NativeData);
				this->m_NativeData = NULL;
			}
		}
	};
}