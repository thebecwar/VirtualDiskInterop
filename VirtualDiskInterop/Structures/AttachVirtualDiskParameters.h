#pragma once


using namespace System;

namespace VirtualDiskInterop
{
	public value class AttachVirtualDiskParametersVersion1
	{
	public:
		/// <summary>
		/// Reserved.
		/// </summary>
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
		void PopulateNativeStruct(ATTACH_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			parameters->Version1.Reserved = 0;
		}
		void ReadNativeStruct(ATTACH_VIRTUAL_DISK_PARAMETERS* parameters)
		{
			this->m_Reserved = parameters->Version1.Reserved;
		}
	};

	/// <summary>
	/// Contains virtual hard disk attach request parameters.
	/// </summary>
	public value class AttachVirtualDiskParameters
	{
	public:
		/// <summary>
		/// An AttachVirtualDiskVersions enumeration that specifies the version of the AttachVirtualDiskVersions structure being passed to or from the VHD functions.
		/// </summary>
		property AttachVirtualDiskVersions Version
		{
			AttachVirtualDiskVersions get()
			{
				return this->m_Version;
			}
			void set(AttachVirtualDiskVersions value)
			{
				this->m_Version = value;
			}
		}
		property AttachVirtualDiskParametersVersion1 Version1
		{
			AttachVirtualDiskParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(AttachVirtualDiskParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
	private:
		AttachVirtualDiskVersions m_Version;
		AttachVirtualDiskParametersVersion1 m_Version1;
	internal:
		ATTACH_VIRTUAL_DISK_PARAMETERS* m_NativeData = NULL;
		ATTACH_VIRTUAL_DISK_PARAMETERS* GetNative()
		{
			if (this->m_NativeData)
			{
				delete this->m_NativeData;
			}
			this->m_NativeData = new ATTACH_VIRTUAL_DISK_PARAMETERS();
			this->m_NativeData->Version = (ATTACH_VIRTUAL_DISK_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case AttachVirtualDiskVersions::Version1:
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
					this->m_Version = (AttachVirtualDiskVersions)this->m_NativeData->Version;
					switch (this->m_Version)
					{
					case AttachVirtualDiskVersions::Version1:
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
