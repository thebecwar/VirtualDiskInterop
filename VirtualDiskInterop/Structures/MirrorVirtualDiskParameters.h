#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class MirrorVirtualDiskParametersVersion1
	{
	public:
		property String^ MirrorVirtualDiskPath
		{
			String^ get()
			{
				return this->m_MirrorVirtualDiskPath;
			}
			void set(String^ value)
			{
				this->m_MirrorVirtualDiskPath = value;
			}
		}
	private:
		String^ m_MirrorVirtualDiskPath;
	};

	public value class MirrorVirtualDiskParameters
	{
	public:
		property MirrorVirtualDiskVersions Version
		{
			MirrorVirtualDiskVersions get()
			{
				return this->m_Version;
			}
			void set(MirrorVirtualDiskVersions value)
			{
				this->m_Version = value;
			}
		}
		property MirrorVirtualDiskParametersVersion1 Version1
		{
			MirrorVirtualDiskParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(MirrorVirtualDiskParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
	private:
		MirrorVirtualDiskVersions m_Version;
		MirrorVirtualDiskParametersVersion1 m_Version1;
	};
}