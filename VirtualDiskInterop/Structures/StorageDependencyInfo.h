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
	private:
		StorageDependencyInfoVersions m_Version;
		unsigned long m_NumberEntries;
		array<StorageDependencyInfoType1>^ m_Version1Entries;
		array<StorageDependencyInfoType2>^ m_Version2Entries;
	};
}