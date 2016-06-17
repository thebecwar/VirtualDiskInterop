#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class OpenVirtualDiskParametersVersion1
	{
	public:
		property unsigned long RWDepth
		{
			unsigned long get()
			{
				return this->m_RWDepth;
			}
			void set(unsigned long value)
			{
				this->m_RWDepth = value;
			}
		}
	private:
		unsigned long m_RWDepth;

	internal:
		void PopulateNativeStruct(OPEN_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			parameters->Version1.RWDepth = this->m_RWDepth;
		}
		void ReadNativeStruct(OPEN_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_RWDepth = parameters->Version1.RWDepth;
		}
	};

	public value class OpenVirtualDiskParametersVersion2
	{
	public:
		property bool GetInfoOnly
		{
			bool get()
			{
				return this->m_GetInfoOnly;
			}
			void set(bool value)
			{
				this->m_GetInfoOnly = value;
			}
		}
		property bool ReadOnly
		{
			bool get()
			{
				return this->m_ReadOnly;
			}
			void set(bool value)
			{
				this->m_ReadOnly = value;
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
		bool m_GetInfoOnly;
		bool m_ReadOnly;
		Guid m_ResiliencyGuid;

	internal:
		void PopulateNativeStruct(OPEN_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			parameters->Version2.GetInfoOnly = (BOOL)this->m_GetInfoOnly;
			parameters->Version2.ReadOnly = (BOOL)this->m_ReadOnly;
			parameters->Version2.ResiliencyGuid = Helpers::ToGUID(this->m_ResiliencyGuid);
		}
		void ReadNativeStruct(OPEN_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_GetInfoOnly = parameters->Version2.GetInfoOnly != 0;
			this->m_ReadOnly = parameters->Version2.ReadOnly != 0;
			this->m_ResiliencyGuid = Helpers::FromGUID(parameters->Version2.ResiliencyGuid);
		}
	};

#ifdef WIN10SUPPORT

	public value class OpenVirtualDiskParametersVersion3
	{
	public:
		property bool GetInfoOnly
		{
			bool get()
			{
				return this->m_GetInfoOnly;
			}
			void set(bool value)
			{
				this->m_GetInfoOnly = value;
			}
		}
		property bool ReadOnly
		{
			bool get()
			{
				return this->m_ReadOnly;
			}
			void set(bool value)
			{
				this->m_ReadOnly = value;
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
		property Guid SnapshotId
		{
			Guid get()
			{
				return this->m_SnapshotId;
			}
			void set(Guid value)
			{
				this->m_SnapshotId = value;
			}
		}
	private:
		bool m_GetInfoOnly;
		bool m_ReadOnly;
		Guid m_ResiliencyGuid;
		Guid m_SnapshotId;
	internal:
		void PopulateNativeStruct(OPEN_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			parameters->Version3.GetInfoOnly = (BOOL)this->m_GetInfoOnly;
			parameters->Version3.ReadOnly = (BOOL)this->m_ReadOnly;
			parameters->Version3.ResiliencyGuid = Helpers::ToGUID(this->m_ResiliencyGuid);
			parameters->Version3.SnapshotId = Helpers::ToGUID(this->m_SnapshotId);
		}
		void ReadNativeStruct(OPEN_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_GetInfoOnly = parameters->Version3.GetInfoOnly != 0;
			this->m_ReadOnly = parameters->Version3.ReadOnly != 0;
			this->m_ResiliencyGuid = Helpers::FromGUID(parameters->Version3.ResiliencyGuid);
			this->m_SnapshotId = Helpers::FromGUID(parameters->Version3.SnapshotId);
		}
	};

#endif

	public value class OpenVirtualDiskParameters
	{
	public:
		property OpenVirtualDiskVersions Version
		{
			OpenVirtualDiskVersions get()
			{
				return this->m_Version;
			}
			void set(OpenVirtualDiskVersions value)
			{
				this->m_Version = value;
			}
		}
		property OpenVirtualDiskParametersVersion1 Version1
		{
			OpenVirtualDiskParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(OpenVirtualDiskParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
		property OpenVirtualDiskParametersVersion2 Version2
		{
			OpenVirtualDiskParametersVersion2 get()
			{
				return this->m_Version2;
			}
			void set(OpenVirtualDiskParametersVersion2 value)
			{
				this->m_Version2 = value;
			}
		}
#ifdef WIN10SUPPORT
		property OpenVirtualDiskParametersVersion3 Version3
		{
			OpenVirtualDiskParametersVersion3 get()
			{
				return this->m_Version3;
			}
			void set(OpenVirtualDiskParametersVersion3 value)
			{
				this->m_Version3 = value;
			}
		}
#endif
	private:
		OpenVirtualDiskVersions m_Version;
		OpenVirtualDiskParametersVersion1 m_Version1;
		OpenVirtualDiskParametersVersion2 m_Version2;
#ifdef WIN10SUPPORT
		OpenVirtualDiskParametersVersion3 m_Version3;
#endif
	internal:
		OPEN_VIRTUAL_DISK_PARAMETERS* m_NativeData = NULL;
		OPEN_VIRTUAL_DISK_PARAMETERS* GetNative()
		{
			if (this->m_NativeData)
			{
				delete this->m_NativeData;
			}
			this->m_NativeData = new OPEN_VIRTUAL_DISK_PARAMETERS();
			this->m_NativeData->Version = (OPEN_VIRTUAL_DISK_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case OpenVirtualDiskVersions::Version1:
				this->m_Version1.PopulateNativeStruct(this->m_NativeData);
				break;
			case OpenVirtualDiskVersions::Version2:
				this->m_Version2.PopulateNativeStruct(this->m_NativeData);
				break;
#ifdef WIN10SUPPORT
			case OpenVirtualDiskVersions::Version3:
				this->m_Version3.PopulateNativeStruct(this->m_NativeData);
				break;
#endif
			default:
				break;
			}
			return this->m_NativeData;
		}
		void ReleaseNative(bool updateData)
		{
			if (this->m_NativeData)
			{
				if (updateData)
				{
					this->m_Version = (OpenVirtualDiskVersions)this->m_NativeData->Version;
					switch (this->m_Version)
					{
					case OpenVirtualDiskVersions::Version1:
						this->m_Version1.ReadNativeStruct(this->m_NativeData);
						break;
					case OpenVirtualDiskVersions::Version2:
						this->m_Version2.ReadNativeStruct(this->m_NativeData);
						break;
#ifdef WIN10SUPPORT
					case OpenVirtualDiskVersions::Version3:
						this->m_Version3.ReadNativeStruct(this->m_NativeData);
						break;
#endif
					}
				}
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
		}
	};
}