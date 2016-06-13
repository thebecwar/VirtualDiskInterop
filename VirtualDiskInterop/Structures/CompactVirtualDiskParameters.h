#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class CompactVirtualDiskParametersVersion1
	{
	public:
		property unsigned long Reserved
		{
			unsigned long get()
			{
				return this->m_Reserved;
			}
			void set(unsigned long value)
			{
				throw gcnew NotSupportedException("Cannot set reserved parameter");
			}
		}
	private:
		unsigned long m_Reserved = 0;
	};

	public value class CompactVirtualDiskParameters
	{
	public:
		property CompactVirtualDiskVersions Version
		{
			CompactVirtualDiskVersions get()
			{
				return this->m_Version;
			}
			void set(CompactVirtualDiskVersions value)
			{
				this->m_Version = value;
			}
		}
		property CompactVirtualDiskParametersVersion1 Version1
		{
			CompactVirtualDiskParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(CompactVirtualDiskParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
	private:
		CompactVirtualDiskVersions m_Version;
		CompactVirtualDiskParametersVersion1 m_Version1;
	};
}