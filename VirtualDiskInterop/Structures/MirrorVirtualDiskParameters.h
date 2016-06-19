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
		LPWSTR m_NativeMirrorVirtualDiskPath;
	internal:
		void PopulateNativeStruct(MIRROR_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_NativeMirrorVirtualDiskPath = Helpers::AllocString(this->m_MirrorVirtualDiskPath);
			parameters->Version1.MirrorVirtualDiskPath = this->m_NativeMirrorVirtualDiskPath;
		}
		void ReadNativeStruct(MIRROR_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_MirrorVirtualDiskPath = gcnew String(parameters->Version1.MirrorVirtualDiskPath);
			this->ReleaseNativeData();
		}
		void ReleaseNativeData()
		{
			if (this->m_NativeMirrorVirtualDiskPath)
			{
				LocalFree(this->m_NativeMirrorVirtualDiskPath);
				this->m_NativeMirrorVirtualDiskPath = NULL;
			}
		}
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
	internal:
		MIRROR_VIRTUAL_DISK_PARAMETERS* m_NativeData = NULL;
		MIRROR_VIRTUAL_DISK_PARAMETERS* GetNative()
		{
			if (this->m_NativeData)
			{
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
			this->m_NativeData = new MIRROR_VIRTUAL_DISK_PARAMETERS();
			this->m_NativeData->Version = (MIRROR_VIRTUAL_DISK_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case MirrorVirtualDiskVersions::Version1:
				this->m_Version1.PopulateNativeStruct(this->m_NativeData);
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
					this->m_Version = (MirrorVirtualDiskVersions)this->m_NativeData->Version;
					switch (this->m_Version)
					{
					case MirrorVirtualDiskVersions::Version1:
						this->m_Version1.ReadNativeStruct(this->m_NativeData);
						break;
					}
				}

				this->m_Version1.ReleaseNativeData();
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
		}
	};
}