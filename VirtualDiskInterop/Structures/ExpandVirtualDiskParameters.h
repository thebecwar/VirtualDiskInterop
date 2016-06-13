#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class ExpandVirtualDiskParametersVersion1
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

	public value class ExpandVirtualDiskParameters
	{
	public:
		property ExpandVirtualDiskVersions Version
		{
			ExpandVirtualDiskVersions get()
			{
				return this->m_Version;
			}
			void set(ExpandVirtualDiskVersions value)
			{
				this->m_Version = value;
			}
		}
		property ExpandVirtualDiskParametersVersion1 Version1
		{
			ExpandVirtualDiskParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(ExpandVirtualDiskParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
	private:
		ExpandVirtualDiskVersions m_Version;
		ExpandVirtualDiskParametersVersion1 m_Version1;
	};
}