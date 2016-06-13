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
	};

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
	private:
		OpenVirtualDiskVersions m_Version;
		OpenVirtualDiskParametersVersion1 m_Version1;
		OpenVirtualDiskParametersVersion2 m_Version2;
	};
}