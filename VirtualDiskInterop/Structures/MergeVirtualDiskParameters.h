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
	internal:
		void PopulateNativeStruct(MERGE_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			parameters->Version1.MergeDepth = this->m_MergeDepth;
		}
		void ReadNativeStruct(MERGE_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_MergeDepth = parameters->Version1.MergeDepth;
		}
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
	internal:
		void PopulateNativeStruct(MERGE_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			parameters->Version2.MergeSourceDepth = this->m_MergeSourceDepth;
			parameters->Version2.MergeTargetDepth = this->m_MergeTargetDepth;
		}
		void ReadNativeStruct(MERGE_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_MergeSourceDepth = parameters->Version2.MergeSourceDepth;
			this->m_MergeTargetDepth = parameters->Version2.MergeTargetDepth;
		}
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
	internal:
		MERGE_VIRTUAL_DISK_PARAMETERS* m_NativeData = NULL;
		MERGE_VIRTUAL_DISK_PARAMETERS* GetNative()
		{
			if (this->m_NativeData)
			{
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
			this->m_NativeData = new MERGE_VIRTUAL_DISK_PARAMETERS();
			this->m_NativeData->Version = (MERGE_VIRTUAL_DISK_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case MergeVirtualDiskVersions::Version1:
				this->m_Version1.PopulateNativeStruct(this->m_NativeData);
				break;
			case MergeVirtualDiskVersions::Version2:
				this->m_Version2.PopulateNativeStruct(this->m_NativeData);
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
					this->m_Version = (MergeVirtualDiskVersions)this->m_NativeData->Version;
					switch (this->m_Version)
					{
					case MergeVirtualDiskVersions::Version1:
						this->m_Version1.ReadNativeStruct(this->m_NativeData);
						break;
					case MergeVirtualDiskVersions::Version2:
						this->m_Version2.ReadNativeStruct(this->m_NativeData);
						break;
					}
				}
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
		}
	};
}