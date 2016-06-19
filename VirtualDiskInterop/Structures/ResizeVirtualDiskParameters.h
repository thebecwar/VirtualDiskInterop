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
	internal:
		void PopulateNativeStruct(RESIZE_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			parameters->Version1.NewSize = this->m_NewSize;
		}
		void ReadNativeStruct(RESIZE_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_NewSize = parameters->Version1.NewSize;
		}
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
	internal:
		RESIZE_VIRTUAL_DISK_PARAMETERS* m_NativeData;
		RESIZE_VIRTUAL_DISK_PARAMETERS* GetNative()
		{
			if (this->m_NativeData)
			{
				this->ReleaseNative(false);
			}
			this->m_NativeData = new RESIZE_VIRTUAL_DISK_PARAMETERS();
			this->m_NativeData->Version = (RESIZE_VIRTUAL_DISK_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case ResizeVirtualDiskVersions::Version1:
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
					this->m_Version = (ResizeVirtualDiskVersions)this->m_NativeData->Version;
					switch (this->m_Version)
					{
					case ResizeVirtualDiskVersions::Version1:
						this->m_Version1.ReadNativeStruct(this->m_NativeData);
						break;
					}
				}
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
		}
	};
}