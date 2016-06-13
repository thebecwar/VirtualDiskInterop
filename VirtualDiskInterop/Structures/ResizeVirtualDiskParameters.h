#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class ResizeVirtualDiskParametersVersion1
	{
	public:
		property unsigned long long NewSize
		{
			unsigned long long get()
			{
				return this->m_NewSize;
			}
			void set(unsigned long long value)
			{
				this->m_NewSize = value;
			}
		}
	private:
		unsigned long long m_NewSize;
	};

	public value class ResizeVirtualDiskParameters
	{
	public:
		property ResizeVirtualDiskVersions Version
		{
			ResizeVirtualDiskVersions get()
			{
				return this->m_Version;
			}
			void set(ResizeVirtualDiskVersions value)
			{
				this->m_Version = value;
			}
		}
		property ResizeVirtualDiskParametersVersion1 Version1
		{
			ResizeVirtualDiskParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(ResizeVirtualDiskParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
	private:
		ResizeVirtualDiskVersions m_Version;
		ResizeVirtualDiskParametersVersion1 m_Version1;
	};
}