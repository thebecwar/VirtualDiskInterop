#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class CreateCirtualDiskParametersVersion1
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
	};

	public value class CreateCirtualDiskParametersVersion2
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
		property _VirtualStorageType ParentVirtualStorageType
		{
			_VirtualStorageType get()
			{
				return this->m_ParentVirtualStorageType;
			}
			void set(_VirtualStorageType value)
			{
				this->m_ParentVirtualStorageType = value;
			}
		}
		property _VirtualStorageType SourceVirtualStorageType
		{
			_VirtualStorageType get()
			{
				return this->m_SourceVirtualStorageType;
			}
			void set(_VirtualStorageType value)
			{
				this->m_SourceVirtualStorageType = value;
			}
		}
	private:
		Guid m_UniqueId;
		unsigned long long m_MaximumSize;
		unsigned long m_BlockSizeInBytes;
		unsigned long m_SectorSizeInBytes;
		String^ m_ParentPath;
		String^ m_SourcePath;
		OpenVirtualDiskFlags m_OpenFlags;
		_VirtualStorageType m_ParentVirtualStorageType;
		_VirtualStorageType m_SourceVirtualStorageType;
		Guid m_ResiliencyGuid;
	};

	public value class CreateCirtualDiskParameters
	{
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
		property CreateCirtualDiskParametersVersion1 Version1
		{
			CreateCirtualDiskParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(CreateCirtualDiskParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
		property CreateCirtualDiskParametersVersion2 Version2
		{
			CreateCirtualDiskParametersVersion2 get()
			{
				return this->m_Version2;
			}
			void set(CreateCirtualDiskParametersVersion2 value)
			{
				this->m_Version2 = value;
			}
		}
	private:
		CreateVirtualDiskVersions m_Version;
		CreateCirtualDiskParametersVersion1 m_Version1;
		CreateCirtualDiskParametersVersion2 m_Version2;
	};
}