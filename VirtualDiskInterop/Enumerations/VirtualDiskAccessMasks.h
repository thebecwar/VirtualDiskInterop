#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains the bit mask for specifying access rights to a virtual hard disk (VHD).
	/// </summary>
	[Flags()]
	public enum class VirtualDiskAccessMasks
	{
		/// <summary>
		/// Open the virtual disk with no access.This is the only supported value when calling CreateVirtualDisk and specifying CREATE_VIRTUAL_DISK_VERSION_2 in the VirtualDiskAccessMask parameter.
		/// </summary>
		None = VIRTUAL_DISK_ACCESS_NONE,
		
		/// <summary>
		/// Open the virtual disk for read-only attach access. The caller must have READ access to the virtual disk image file. If used in a request to open a virtual disk that is already open, the other handles must be limited to either VIRTUAL_DISK_ACCESS_DETACH or VIRTUAL_DISK_ACCESS_GET_INFO access, otherwise the open request with this flag will fail.
		/// </summary>
		AttachReadOnly = VIRTUAL_DISK_ACCESS_ATTACH_RO,
		
		/// <summary>
		/// Open the virtual disk for read-write attaching access. The caller must have (READ | WRITE) access to the virtual disk image file. If used in a request to open a virtual disk that is already open, the other handles must be limited to either VIRTUAL_DISK_ACCESS_DETACH or VIRTUAL_DISK_ACCESS_GET_INFO access, otherwise the open request with this flag will fail. If the virtual disk is part of a differencing chain, the disk for this request cannot be less than the RWDepth specified during the prior open request for that differencing chain.
		/// </summary>
		AttachReadWrite = VIRTUAL_DISK_ACCESS_ATTACH_RW,
		
		/// <summary>
		/// Open the virtual disk to allow detaching of an attached virtual disk. The caller must have (FILE_READ_ATTRIBUTES | FILE_READ_DATA) access to the virtual disk image file.
		/// </summary>
		Detach = VIRTUAL_DISK_ACCESS_DETACH,
		
		/// <summary>
		/// Information retrieval access to the VHD. The caller must have READ access to the virtual disk image file.
		/// </summary>
		GetInfo = VIRTUAL_DISK_ACCESS_GET_INFO,
		
		/// <summary>
		/// VHD creation access.
		/// </summary>
		Create = VIRTUAL_DISK_ACCESS_CREATE,
		
		/// <summary>
		/// Open the VHD to perform offline meta-operations. The caller must have (READ | WRITE) access to the virtual disk image file, up to RWDepth if working with a differencing chain. If the VHD is part of a differencing chain, the backing store (host volume) is opened in RW exclusive mode up to RWDepth.
		/// </summary>
		MetaOperations = VIRTUAL_DISK_ACCESS_METAOPS,
		
		/// <summary>
		/// Reserved.
		/// </summary>
		Read = VIRTUAL_DISK_ACCESS_READ,
		
		/// <summary>
		/// Allows unrestricted access to the VHD. The caller must have unrestricted access rights to the virtual disk image file.
		/// </summary>
		All = VIRTUAL_DISK_ACCESS_ALL,
		
		/// <summary>
		/// Reserved.
		/// </summary>
		Writable = VIRTUAL_DISK_ACCESS_WRITABLE,
	};

}
