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
	internal:
		void PopulateNativeStruct(EXPAND_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			parameters->Version1.NewSize = this->m_NewSize;
		}
		void ReadNativeStruct(EXPAND_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_NewSize = parameters->Version1.NewSize;
		}
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
	internal:
		EXPAND_VIRTUAL_DISK_PARAMETERS* m_NativeData;
		EXPAND_VIRTUAL_DISK_PARAMETERS* GetNative()
		{
			if (this->m_NativeData)
			{
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
			this->m_NativeData = new EXPAND_VIRTUAL_DISK_PARAMETERS();
			this->m_NativeData->Version = (EXPAND_VIRTUAL_DISK_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case ExpandVirtualDiskVersions::Version1:
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
					this->m_Version = (ExpandVirtualDiskVersions)this->m_NativeData->Version;
					switch (this->m_Version)
					{
					case ExpandVirtualDiskVersions::Version1:
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