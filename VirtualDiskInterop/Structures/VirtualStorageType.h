#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class _VirtualStorageType
	{
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
	};
}