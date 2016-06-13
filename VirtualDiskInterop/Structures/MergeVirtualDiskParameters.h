#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class MergeVirtualDiskParametersVersion1
	{
	public:
		property unsigned long MergeDepth
		{
			unsigned long get()
			{
				return this->m_MergeDepth;
			}
			void set(unsigned long value)
			{
				this->m_MergeDepth = value;
			}
		}
	private:
		unsigned long m_MergeDepth;
	};

	public value class MergeVirtualDiskParametersVersion2
	{
	public:
		property unsigned long MergeSourceDepth
		{
			unsigned long get()
			{
				return this->m_MergeSourceDepth;
			}
			void set(unsigned long value)
			{
				this->m_MergeSourceDepth = value;
			}
		}
		property unsigned long MergeTargetDepth
		{
			unsigned long get()
			{
				return this->m_MergeTargetDepth;
			}
			void set(unsigned long value)
			{
				this->m_MergeTargetDepth = value;
			}
		}
	private:
		unsigned long m_MergeSourceDepth;
		unsigned long m_MergeTargetDepth;
	};

	public value class MergeVirtualDiskParameters
	{
	public:
		property MergeVirtualDiskVersions Version
		{
			MergeVirtualDiskVersions get()
			{
				return this->m_Version;
			}
			void set(MergeVirtualDiskVersions value)
			{
				this->m_Version = value;
			}
		}
		property MergeVirtualDiskParametersVersion1 Version1
		{
			MergeVirtualDiskParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(MergeVirtualDiskParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
		property MergeVirtualDiskParametersVersion2 Version2
		{
			MergeVirtualDiskParametersVersion2 get()
			{
				return this->m_Version2;
			}
			void set(MergeVirtualDiskParametersVersion2 value)
			{
				this->m_Version2 = value;
			}
		}
	private:
		MergeVirtualDiskVersions m_Version;
		MergeVirtualDiskParametersVersion1 m_Version1;
		MergeVirtualDiskParametersVersion2 m_Version2;
	};
}