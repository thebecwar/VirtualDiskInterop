#pragma once

using namespace System;
using namespace System::Runtime::InteropServices;

namespace VirtualDiskInterop
{
	public value class CreateVirtualDiskParametersVersion1
	{
	public:
		property Guid UniqueId
		{
			Guid get()
			{
				return this->m_UniqueId;
			}
			void set(Guid value)
			{
				this->m_UniqueId = value;
			}
		}
		property unsigned long long MaximumSize
		{
			unsigned long long get()
			{
				return this->m_MaximumSize;
			}
			void set(unsigned long long value)
			{
				this->m_MaximumSize = value;
			}
		}
		property unsigned long BlockSizeInBytes
		{
			unsigned long get()
			{
				return this->m_BlockSizeInBytes;
			}
			void set(unsigned long value)
			{
				this->m_BlockSizeInBytes = value;
			}
		}
		property unsigned long SectorSizeInBytes
		{
			unsigned long get()
			{
				return this->m_SectorSizeInBytes;
			}
			void set(unsigned long value)
			{
				this->m_SectorSizeInBytes = value;
			}
		}
		property String^ ParentPath
		{
			String^ get()
			{
				return this->m_ParentPath;
			}
			void set(String^ value)
			{
				this->m_ParentPath = value;
			}
		}
		property String^ SourcePath
		{
			String^ get()
			{
				return this->m_SourcePath;
			}
			void set(String^ value)
			{
				this->m_SourcePath = value;
			}
		}
	private:
		Guid m_UniqueId;
		unsigned long long m_MaximumSize;
		unsigned long m_BlockSizeInBytes;
		unsigned long m_SectorSizeInBytes;
		String^ m_ParentPath;
		String^ m_SourcePath;
	internal:
		LPWSTR m_NativeParentPath;
		LPWSTR m_NativeSourcePath;
		void PopulateNativeStruct(CREATE_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->ReleaseNativeData();

			parameters->Version1.UniqueId = Helpers::ToGUID(this->m_UniqueId);
			parameters->Version1.MaximumSize = this->m_MaximumSize;
			parameters->Version1.BlockSizeInBytes = this->m_BlockSizeInBytes;
			parameters->Version1.SectorSizeInBytes = this->m_SectorSizeInBytes;
			
			this->m_NativeParentPath = Helpers::AllocString(this->m_ParentPath);
			parameters->Version1.ParentPath = this->m_NativeParentPath;
			
			this->m_NativeSourcePath = Helpers::AllocString(this->m_SourcePath);
			parameters->Version1.SourcePath = this->m_NativeSourcePath;
		}
		void ReadNativeStruct(CREATE_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_UniqueId = Helpers::FromGUID(parameters->Version1.UniqueId);
			this->m_MaximumSize = parameters->Version1.MaximumSize;
			this->m_BlockSizeInBytes = parameters->Version1.BlockSizeInBytes;
			this->m_SectorSizeInBytes = parameters->Version1.SectorSizeInBytes;
			if (this->m_NativeParentPath != NULL)
			{
				this->m_ParentPath = gcnew String(this->m_NativeParentPath);
			}
			if (this->m_NativeSourcePath != NULL)
			{
				this->m_SourcePath = gcnew String(this->m_NativeSourcePath);
			}

			this->ReleaseNativeData();
		}
		void ReleaseNativeData()
		{
			if (this->m_NativeParentPath != NULL)
			{
				LocalFree(this->m_NativeParentPath);
				this->m_NativeParentPath = NULL;
			}
			if (this->m_NativeSourcePath != NULL)
			{
				LocalFree(this->m_NativeSourcePath);
				this->m_NativeSourcePath = NULL;
			}
		}
	};

	public value class CreateVirtualDiskParametersVersion2
	{
	public:
		property Guid UniqueId
		{
			Guid get()
			{
				return this->m_UniqueId;
			}
			void set(Guid value)
			{
				this->m_UniqueId = value;
			}
		}
		property unsigned long long MaximumSize
		{
			unsigned long long get()
			{
				return this->m_MaximumSize;
			}
			void set(unsigned long long value)
			{
				this->m_MaximumSize = value;
			}
		}
		property unsigned long BlockSizeInBytes
		{
			unsigned long get()
			{
				return this->m_BlockSizeInBytes;
			}
			void set(unsigned long value)
			{
				this->m_BlockSizeInBytes = value;
			}
		}
		property unsigned long SectorSizeInBytes
		{
			unsigned long get()
			{
				return this->m_SectorSizeInBytes;
			}
			void set(unsigned long value)
			{
				this->m_SectorSizeInBytes = value;
			}
		}
		property unsigned long PhysicalSectorSizeInBytes
		{
			unsigned long get()
			{
				return this->m_PhysicalSectorSizeInBytes;
			}
			void set(unsigned long value)
			{
				this->m_PhysicalSectorSizeInBytes = value;
			}
		}
		property String^ ParentPath
		{
			String^ get()
			{
				return this->m_ParentPath;
			}
			void set(String^ value)
			{
				this->m_ParentPath = value;
			}
		}
		property String^ SourcePath
		{
			String^ get()
			{
				return this->m_SourcePath;
			}
			void set(String^ value)
			{
				this->m_SourcePath = value;
			}
		}
		property OpenVirtualDiskFlags OpenFlags
		{
			OpenVirtualDiskFlags get()
			{
				return this->m_OpenFlags;
			}
			void set(OpenVirtualDiskFlags value)
			{
				this->m_OpenFlags = value;
			}
		}
		property VirtualStorageType ParentVirtualStorageType
		{
			VirtualStorageType get()
			{
				return this->m_ParentVirtualStorageType;
			}
			void set(VirtualStorageType value)
			{
				this->m_ParentVirtualStorageType = value;
			}
		}
		property VirtualStorageType SourceVirtualStorageType
		{
			VirtualStorageType get()
			{
				return this->m_SourceVirtualStorageType;
			}
			void set(VirtualStorageType value)
			{
				this->m_SourceVirtualStorageType = value;
			}
		}
		property Guid ResiliencyGuid
		{
			Guid get()
			{
				return this->m_ResiliencyGuid;
			}
			void set(Guid value)
			{
				this->m_ResiliencyGuid = value;
			}
		}
	private:
		Guid m_UniqueId;
		unsigned long long m_MaximumSize;
		unsigned long m_BlockSizeInBytes;
		unsigned long m_SectorSizeInBytes;
		unsigned long m_PhysicalSectorSizeInBytes;
		String^ m_ParentPath;
		String^ m_SourcePath;
		OpenVirtualDiskFlags m_OpenFlags;
		VirtualStorageType m_ParentVirtualStorageType;
		VirtualStorageType m_SourceVirtualStorageType;
		Guid m_ResiliencyGuid;
	internal:
		LPWSTR m_NativeParentPath;
		LPWSTR m_NativeSourcePath;
		void PopulateNativeStruct(CREATE_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->ReleaseNativeData();

			parameters->Version2.UniqueId = Helpers::ToGUID(this->m_UniqueId);
			parameters->Version2.MaximumSize = this->m_MaximumSize;
			parameters->Version2.BlockSizeInBytes = this->m_BlockSizeInBytes;
			parameters->Version2.SectorSizeInBytes = this->m_SectorSizeInBytes;

			this->m_NativeParentPath = Helpers::AllocString(this->m_ParentPath);
			parameters->Version2.ParentPath = this->m_NativeParentPath;

			this->m_NativeSourcePath = Helpers::AllocString(this->m_SourcePath);
			parameters->Version2.SourcePath = this->m_NativeSourcePath;

			parameters->Version2.OpenFlags = (OPEN_VIRTUAL_DISK_FLAG)this->m_OpenFlags;
			parameters->Version2.ParentVirtualStorageType.DeviceId = (ULONG)this->m_ParentVirtualStorageType.DeviceId;
			parameters->Version2.ParentVirtualStorageType.VendorId = Helpers::ToGUID(this->m_ParentVirtualStorageType.VendorId);
			parameters->Version2.SourceVirtualStorageType.DeviceId = (ULONG)this->m_SourceVirtualStorageType.DeviceId;
			parameters->Version2.SourceVirtualStorageType.VendorId = Helpers::ToGUID(this->m_SourceVirtualStorageType.VendorId);
			parameters->Version2.ResiliencyGuid = Helpers::ToGUID(this->m_ResiliencyGuid);
		}
		void ReadNativeStruct(CREATE_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_UniqueId = Helpers::FromGUID(parameters->Version2.UniqueId);
			this->m_MaximumSize = parameters->Version2.MaximumSize;
			this->m_BlockSizeInBytes = parameters->Version2.BlockSizeInBytes;
			this->m_SectorSizeInBytes = parameters->Version2.SectorSizeInBytes;
			if (this->m_NativeParentPath != NULL)
			{
				this->m_ParentPath = gcnew String(this->m_NativeParentPath);
			}
			if (this->m_NativeSourcePath != NULL)
			{
				this->m_SourcePath = gcnew String(this->m_NativeSourcePath);
			}

			this->m_OpenFlags = (OpenVirtualDiskFlags)parameters->Version2.OpenFlags;
			this->m_ParentVirtualStorageType.DeviceId = (VirtualStorageDeviceTypes)parameters->Version2.ParentVirtualStorageType.DeviceId;
			this->m_ParentVirtualStorageType.VendorId = Helpers::FromGUID(parameters->Version2.ParentVirtualStorageType.VendorId);
			this->m_SourceVirtualStorageType.DeviceId = (VirtualStorageDeviceTypes)parameters->Version2.SourceVirtualStorageType.DeviceId;
			this->m_SourceVirtualStorageType.VendorId = Helpers::FromGUID(parameters->Version2.SourceVirtualStorageType.VendorId);
			this->m_ResiliencyGuid = Helpers::FromGUID(parameters->Version2.ResiliencyGuid);

			this->ReleaseNativeData();
		}
		void ReleaseNativeData()
		{
			if (this->m_NativeParentPath != NULL)
			{
				LocalFree(this->m_NativeParentPath);
				this->m_NativeParentPath = NULL;
			}
			if (this->m_NativeSourcePath != NULL)
			{
				LocalFree(this->m_NativeSourcePath);
				this->m_NativeSourcePath = NULL;
			}
		}
	};

#ifdef WIN10SUPPORT
	public value class CreateVirtualDiskParametersVersion3
	{
	public:
		property Guid UniqueId
		{
			Guid get()
			{
				return this->m_UniqueId;
			}
			void set(Guid value)
			{
				this->m_UniqueId = value;
			}
		}
		property unsigned long long MaximumSize
		{
			unsigned long long get()
			{
				return this->m_MaximumSize;
			}
			void set(unsigned long long value)
			{
				this->m_MaximumSize = value;
			}
		}
		property unsigned long BlockSizeInBytes
		{
			unsigned long get()
			{
				return this->m_BlockSizeInBytes;
			}
			void set(unsigned long value)
			{
				this->m_BlockSizeInBytes = value;
			}
		}
		property unsigned long SectorSizeInBytes
		{
			unsigned long get()
			{
				return this->m_SectorSizeInBytes;
			}
			void set(unsigned long value)
			{
				this->m_SectorSizeInBytes = value;
			}
		}
		property unsigned long PhysicalSectorSizeInBytes
		{
			unsigned long get()
			{
				return this->m_PhysicalSectorSizeInBytes;
			}
			void set(unsigned long value)
			{
				this->m_PhysicalSectorSizeInBytes = value;
			}
		}
		property String^ ParentPath
		{
			String^ get()
			{
				return this->m_ParentPath;
			}
			void set(String^ value)
			{
				this->m_ParentPath = value;
			}
		}
		property String^ SourcePath
		{
			String^ get()
			{
				return this->m_SourcePath;
			}
			void set(String^ value)
			{
				this->m_SourcePath = value;
			}
		}
		property OpenVirtualDiskFlags OpenFlags
		{
			OpenVirtualDiskFlags get()
			{
				return this->m_OpenFlags;
			}
			void set(OpenVirtualDiskFlags value)
			{
				this->m_OpenFlags = value;
			}
		}
		property VirtualStorageType ParentVirtualStorageType
		{
			VirtualStorageType get()
			{
				return this->m_ParentVirtualStorageType;
			}
			void set(VirtualStorageType value)
			{
				this->m_ParentVirtualStorageType = value;
			}
		}
		property VirtualStorageType SourceVirtualStorageType
		{
			VirtualStorageType get()
			{
				return this->m_SourceVirtualStorageType;
			}
			void set(VirtualStorageType value)
			{
				this->m_SourceVirtualStorageType = value;
			}
		}
		property Guid ResiliencyGuid
		{
			Guid get()
			{
				return this->m_ResiliencyGuid;
			}
			void set(Guid value)
			{
				this->m_ResiliencyGuid = value;
			}
		}
		property String^ SourceLimitPath
		{
			String^ get()
			{
				return this->m_SourceLimitPath;
			}
			void set(String^ value)
			{
				this->m_SourceLimitPath = value;
			}
		}
		property VirtualStorageType BackingStorageType
		{
			VirtualStorageType get()
			{
				return this->m_BackingStorageType;
			}
			void set(VirtualStorageType value)
			{
				this->m_BackingStorageType = value;
			}
		}
	private:
		Guid m_UniqueId;
		unsigned long long m_MaximumSize;
		unsigned long m_BlockSizeInBytes;
		unsigned long m_SectorSizeInBytes;
		unsigned long m_PhysicalSectorSizeInBytes;
		String^ m_ParentPath;
		String^ m_SourcePath;
		OpenVirtualDiskFlags m_OpenFlags;
		VirtualStorageType m_ParentVirtualStorageType;
		VirtualStorageType m_SourceVirtualStorageType;
		Guid m_ResiliencyGuid;
		String^ m_SourceLimitPath;
		VirtualStorageType m_BackingStorageType;
	internal:
		LPWSTR m_NativeParentPath;
		LPWSTR m_NativeSourcePath;
		LPWSTR m_NativeSourceLimitPath;
		void PopulateNativeStruct(CREATE_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->ReleaseNativeData();

			parameters->Version3.UniqueId = Helpers::ToGUID(this->m_UniqueId);
			parameters->Version3.MaximumSize = this->m_MaximumSize;
			parameters->Version3.BlockSizeInBytes = this->m_BlockSizeInBytes;
			parameters->Version3.SectorSizeInBytes = this->m_SectorSizeInBytes;

			this->m_NativeParentPath = Helpers::AllocString(this->m_ParentPath);
			parameters->Version3.ParentPath = this->m_NativeParentPath;

			this->m_NativeSourcePath = Helpers::AllocString(this->m_SourcePath);
			parameters->Version3.SourcePath = this->m_NativeSourcePath;

			parameters->Version3.OpenFlags = (OPEN_VIRTUAL_DISK_FLAG)this->m_OpenFlags;
			parameters->Version3.ParentVirtualStorageType.DeviceId = (ULONG)this->m_ParentVirtualStorageType.DeviceId;
			parameters->Version3.ParentVirtualStorageType.VendorId = Helpers::ToGUID(this->m_ParentVirtualStorageType.VendorId);
			parameters->Version3.SourceVirtualStorageType.DeviceId = (ULONG)this->m_SourceVirtualStorageType.DeviceId;
			parameters->Version3.SourceVirtualStorageType.VendorId = Helpers::ToGUID(this->m_SourceVirtualStorageType.VendorId);
			parameters->Version3.ResiliencyGuid = Helpers::ToGUID(this->m_ResiliencyGuid);

			this->m_NativeSourceLimitPath = Helpers::AllocString(this->m_SourceLimitPath);
			parameters->Version3.SourceLimitPath = this->m_NativeSourceLimitPath;

			parameters->Version3.BackingStorageType.DeviceId = (ULONG)this->m_BackingStorageType.DeviceId;
			parameters->Version3.BackingStorageType.VendorId = Helpers::ToGUID(this->m_BackingStorageType.VendorId);
		}
		void ReadNativeStruct(CREATE_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_UniqueId = Helpers::FromGUID(parameters->Version2.UniqueId);
			this->m_MaximumSize = parameters->Version2.MaximumSize;
			this->m_BlockSizeInBytes = parameters->Version2.BlockSizeInBytes;
			this->m_SectorSizeInBytes = parameters->Version2.SectorSizeInBytes;
			if (this->m_NativeParentPath != NULL)
			{
				this->m_ParentPath = gcnew String(this->m_NativeParentPath);
			}
			if (this->m_NativeSourcePath != NULL)
			{
				this->m_SourcePath = gcnew String(this->m_NativeSourcePath);
			}

			this->m_OpenFlags = (OpenVirtualDiskFlags)parameters->Version2.OpenFlags;
			this->m_ParentVirtualStorageType.DeviceId = (VirtualStorageDeviceTypes)parameters->Version2.ParentVirtualStorageType.DeviceId;
			this->m_ParentVirtualStorageType.VendorId = Helpers::FromGUID(parameters->Version2.ParentVirtualStorageType.VendorId);
			this->m_SourceVirtualStorageType.DeviceId = (VirtualStorageDeviceTypes)parameters->Version2.SourceVirtualStorageType.DeviceId;
			this->m_SourceVirtualStorageType.VendorId = Helpers::FromGUID(parameters->Version2.SourceVirtualStorageType.VendorId);
			this->m_ResiliencyGuid = Helpers::FromGUID(parameters->Version2.ResiliencyGuid);

			if (this->m_NativeSourceLimitPath != NULL)
			{
				this->m_SourceLimitPath = gcnew String(this->m_NativeSourceLimitPath);
			}

			this->m_BackingStorageType.DeviceId = (VirtualStorageDeviceTypes)parameters->Version3.BackingStorageType.DeviceId;
			this->m_BackingStorageType.VendorId = Helpers::FromGUID(parameters->Version3.BackingStorageType.VendorId);

			this->ReleaseNativeData();
		}
		void ReleaseNativeData()
		{
			if (this->m_NativeParentPath != NULL)
			{
				LocalFree(this->m_NativeParentPath);
				this->m_NativeParentPath = NULL;
			}
			if (this->m_NativeSourcePath != NULL)
			{
				LocalFree(this->m_NativeSourcePath);
				this->m_NativeSourcePath = NULL;
			}
			if (this->m_NativeSourceLimitPath != NULL)
			{
				LocalFree(this->m_NativeSourceLimitPath);
				this->m_NativeSourceLimitPath = NULL;
			}
		}
	};
#endif

	public value class CreateVirtualDiskParameters
	{
		// constants
	public:
		static const unsigned long DefaultBlockSize = CREATE_VIRTUAL_DISK_PARAMETERS_DEFAULT_BLOCK_SIZE;
		static const unsigned long DefaultSectorSize = CREATE_VIRTUAL_DISK_PARAMETERS_DEFAULT_SECTOR_SIZE;
	public:
		property CreateVirtualDiskVersions Version
		{
			CreateVirtualDiskVersions get()
			{
				return this->m_Version;
			}
			void set(CreateVirtualDiskVersions value)
			{
				this->m_Version = value;
			}
		}
		property CreateVirtualDiskParametersVersion1 Version1
		{
			CreateVirtualDiskParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(CreateVirtualDiskParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
		property CreateVirtualDiskParametersVersion2 Version2
		{
			CreateVirtualDiskParametersVersion2 get()
			{
				return this->m_Version2;
			}
			void set(CreateVirtualDiskParametersVersion2 value)
			{
				this->m_Version2 = value;
			}
		}
#ifdef WIN10SUPPORT
		property CreateVirtualDiskParametersVersion3 Version3
		{
			CreateVirtualDiskParametersVersion3 get()
			{
				return this->m_Version3;
			}
			void set(CreateVirtualDiskParametersVersion3 value)
			{
				this->m_Version3 = value;
			}
		}
#endif
	private:
		CreateVirtualDiskVersions m_Version;
		CreateVirtualDiskParametersVersion1 m_Version1;
		CreateVirtualDiskParametersVersion2 m_Version2;
#ifdef WIN10SUPPORT
		CreateVirtualDiskParametersVersion3 m_Version3;
#endif
	internal:
		CREATE_VIRTUAL_DISK_PARAMETERS* m_NativeData = NULL;
		CREATE_VIRTUAL_DISK_PARAMETERS* GetNative()
		{
			if (this->m_NativeData)
			{
				delete this->m_NativeData;
			}
			this->m_NativeData = new CREATE_VIRTUAL_DISK_PARAMETERS();

			switch (this->m_Version)
			{
			case CreateVirtualDiskVersions::Version1:
				this->m_Version1.PopulateNativeStruct(this->m_NativeData);
				break;
			case CreateVirtualDiskVersions::Version2:
				this->m_Version2.PopulateNativeStruct(this->m_NativeData);
				break;
#ifdef WIN10SUPPORT
			case CreateVirtualDiskVersions::Version3:
				this->m_Version3.PopulateNativeStruct(this->m_NativeData);
				break;
#endif
			}
			return this->m_NativeData;
		}
		void ReleaseNative(bool updateData)
		{
			if (this->m_NativeData != NULL)
			{
				if (updateData)
				{
					switch (this->m_Version)
					{
					case CreateVirtualDiskVersions::Version1:
						this->m_Version1.ReadNativeStruct(this->m_NativeData);
						break;
					case CreateVirtualDiskVersions::Version2:
						this->m_Version2.ReadNativeStruct(this->m_NativeData);
						break;
#ifdef WIN10SUPPORT
					case CreateVirtualDiskVersions::Version3:
						this->m_Version3.ReadNativeStruct(this->m_NativeData);
						break;
#endif
					}
				}

				this->m_Version1.ReleaseNativeData();
				this->m_Version2.ReleaseNativeData();
#ifdef WIN10SUPPORT
				this->m_Version3.ReleaseNativeData();
#endif

				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
		}


	};
}