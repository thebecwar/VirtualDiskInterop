#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	/// <summary>
	/// Enumerates the available flags for the ResizeVirtualDisk function.
	/// </summary>
	[Flags()]
	public enum class ProviderSpecificSubtypes : ULONG
	{
		/// <summary>
		/// No provider-specific subtype specified.
		/// </summary>
		None = 0,

		Fixed = 2,
		DynamicallyExpandable = 3,
		Differencing = 4,
	};
}