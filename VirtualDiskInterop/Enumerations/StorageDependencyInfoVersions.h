#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Contains the version of the virtual hard disk (VHD) STORAGE_DEPENDENCY_INFO structure to use in calls to VHD functions.
	/// </summary>
	public enum class StorageDependencyInfoVersions
	{
		/// <summary>
		/// The version is not specified.
		/// </summary>
		Unspecified = STORAGE_DEPENDENCY_INFO_VERSION_UNSPECIFIED,
		Version1 = STORAGE_DEPENDENCY_INFO_VERSION_1,
		Version2 = STORAGE_DEPENDENCY_INFO_VERSION_2,
	};
}
