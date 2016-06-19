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
	internal:
		void PopulateNativeStruct(COMPACT_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			parameters->Version1.Reserved = this->m_Reserved;
		}
		void ReadNativeStruct(COMPACT_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_Reserved = parameters->Version1.Reserved;
		}
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
	internal:
		COMPACT_VIRTUAL_DISK_PARAMETERS* m_NativeData = NULL;
		COMPACT_VIRTUAL_DISK_PARAMETERS* GetNative()
		{
			if (this->m_NativeData)
			{
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
			this->m_NativeData = new COMPACT_VIRTUAL_DISK_PARAMETERS();
			this->m_NativeData->Version = (COMPACT_VIRTUAL_DISK_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case CompactVirtualDiskVersions::Version1:
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
					this->m_Version = (CompactVirtualDiskVersions)this->m_NativeData->Version;
					switch (this->m_Version)
					{
					case CompactVirtualDiskVersions::Version1:
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