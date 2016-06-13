#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	[Flags()]
	public enum class VirtualDiskAccessMasks
	{
		None = VIRTUAL_DISK_ACCESS_NONE,
		AttachReadOnly = VIRTUAL_DISK_ACCESS_ATTACH_RO,
		AttachReadWrite = VIRTUAL_DISK_ACCESS_ATTACH_RW,
		Detach = VIRTUAL_DISK_ACCESS_DETACH,
		GetInfo = VIRTUAL_DISK_ACCESS_GET_INFO,
		Create = VIRTUAL_DISK_ACCESS_CREATE,
		MetaOperations = VIRTUAL_DISK_ACCESS_METAOPS,
		Read = VIRTUAL_DISK_ACCESS_READ,
		All = VIRTUAL_DISK_ACCESS_ALL,
		Writable = VIRTUAL_DISK_ACCESS_WRITABLE,
	};

}