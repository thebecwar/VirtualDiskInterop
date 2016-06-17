#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class _VirtualStorageType
	{
	public:
		// Taken from VirtDisk.h
		static const Guid VendorIdUnknown = Guid(0x00000000, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
		static const Guid VendorIdMicrosoft = Guid(0xec984aec, 0xa0f9, 0x47e9, 0x90, 0x1f, 0x71, 0x41, 0x5a, 0x66, 0x34, 0x5b);

	public:
		property VirtualStorageDeviceTypes DeviceId
		{
			VirtualStorageDeviceTypes get()
			{
				return this->m_DeviceId;
			}
			void set(VirtualStorageDeviceTypes value)
			{
				this->m_DeviceId = value;
			}
		}
		property Guid VendorId
		{
			Guid get()
			{
				return this->m_VendorId;
			}
			void set(Guid value)
			{
				this->m_VendorId = value;
			}
		}
	private:
		VirtualStorageDeviceTypes m_DeviceId;
		Guid m_VendorId;

	internal:
		VIRTUAL_STORAGE_TYPE* m_NativeData = NULL;
		VIRTUAL_STORAGE_TYPE* GetNative()
		{
			if (this->m_NativeData)
			{
				delete this->m_NativeData;
			}
			this->m_NativeData = new VIRTUAL_STORAGE_TYPE();
			this->m_NativeData->DeviceId = (ULONG)this->m_DeviceId;
			this->m_NativeData->VendorId = Helpers::ToGUID(this->m_VendorId);
			return this->m_NativeData;
		}
		void ReleaseNative(bool updateData)
		{
			if (this->m_NativeData)
			{
				if (updateData)
				{
					this->m_DeviceId = (VirtualStorageDeviceTypes)this->m_NativeData->DeviceId;
					this->m_VendorId = Helpers::FromGUID(this->m_NativeData->VendorId);
				}
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
		}
	};
}