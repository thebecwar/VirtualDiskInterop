#pragma once


using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains the virtual storage device type
	/// </summary>
	public enum class VirtualStorageDeviceTypes
	{
		Unknown = VIRTUAL_STORAGE_TYPE_DEVICE_UNKNOWN,
		Iso = VIRTUAL_STORAGE_TYPE_DEVICE_ISO,
		Vhd = VIRTUAL_STORAGE_TYPE_DEVICE_VHD,
		Vhdx = VIRTUAL_STORAGE_TYPE_DEVICE_VHDX,
	};
}
