#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public enum class StorageDependencyInfoVersions
	{
		Unspecified = STORAGE_DEPENDENCY_INFO_VERSION_UNSPECIFIED,
		Version1 = STORAGE_DEPENDENCY_INFO_VERSION_1,
		Version2 = STORAGE_DEPENDENCY_INFO_VERSION_2,
	};
}