#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class GetVirtualDiskInfoSize
	{
	public:
		property unsigned long long VirtualSize
		{
			unsigned long long get()
			{
				return this->m_VirtualSize;
			}
			void set(unsigned long long value)
			{
				this->m_VirtualSize = value;
			}
		}
		property unsigned long long PhysicalSize
		{
			unsigned long long get()
			{
				return this->m_PhysicalSize;
			}
			void set(unsigned long long value)
			{
				this->m_PhysicalSize = value;
			}
		}
		property unsigned long BlockSize
		{
			unsigned long get()
			{
				return this->m_BlockSize;
			}
			void set(unsigned long value)
			{
				this->m_BlockSize = value;
			}
		}
		property unsigned long SectorSize
		{
			unsigned long get()
			{
				return this->m_SectorSize;
			}
			void set(unsigned long value)
			{
				this->m_SectorSize = value;
			}
		}
	private:
		unsigned long long m_VirtualSize;
		unsigned long long m_PhysicalSize;
		unsigned long m_BlockSize;
		unsigned long m_SectorSize;
	};

	public value class GetVirtualDiskInfoParentLocation
	{
	public:
		property bool ParentResolved
		{
			bool get()
			{
				return this->m_ParentResolved;
			}
			void set(bool value)
			{
				this->m_ParentResolved = value;
			}
		}
		property String^ ParentLocationBuffer
		{
			String^ get()
			{
				return this->m_ParentLocationBuffer;
			}
			void set(String^ value)
			{
				this->m_ParentLocationBuffer = value;
			}
		}
	private:
		bool m_ParentResolved;
		String^ m_ParentLocationBuffer;
	};

	public value class GetVirtualDiskInfoPhysicalDisk
	{
	public:
		property unsigned long LogicalSectorSize
		{
			unsigned long get()
			{
				return this->m_LogicalSectorSize;
			}
			void set(unsigned long value)
			{
				this->m_LogicalSectorSize = value;
			}
		}
		property unsigned long PhysicalSectorSize
		{
			unsigned long get()
			{
				return this->m_PhysicalSectorSize;
			}
			void set(unsigned long value)
			{
				this->m_PhysicalSectorSize = value;
			}
		}
		property bool IsRemote
		{
			bool get()
			{
				return this->m_IsRemote;
			}
			void set(bool value)
			{
				this->m_IsRemote = value;
			}
		}
	private:
		unsigned long m_LogicalSectorSize;
		unsigned long m_PhysicalSectorSize;
		bool m_IsRemote;
	};
	
#ifdef WIN10SUPPORT
	public value class GetVirtualDiskInfoChangeTrackingState
	{
	public:
		property bool Enabled
		{
			bool get()
			{
				return this->m_Enabled;
			}
			void set(bool value)
			{
				this->m_Enabled = value;
			}
		}
		property bool NewerChanges
		{
			bool get()
			{
				return this->m_NewerChanges;
			}
			void set(bool value)
			{
				this->m_NewerChanges = value;
			}
		}
		property String^ MostRecentId
		{
			String^ get()
			{
				return this->m_MostRecentId;
			}
			void set(String^ value)
			{
				this->m_MostRecentId = value;
			}
		}
	private:
		bool m_Enabled;
		bool m_NewerChanges;
		String^ m_MostRecentId;
	};
#endif

	public value class GetVirtualDiskInfo
	{
	public:
		property GetVirtualDiskInfoVersions Version
		{
			GetVirtualDiskInfoVersions get()
			{
				return this->m_Version;
			}
			void set(GetVirtualDiskInfoVersions value)
			{
				this->m_Version = value;
			}
		}
		property GetVirtualDiskInfoSize Size
		{
			GetVirtualDiskInfoSize get()
			{
				return this->m_Size;
			}
			void set(GetVirtualDiskInfoSize value)
			{
				this->m_Size = value;
			}
		}
		property Guid Identifier
		{
			Guid get()
			{
				return this->m_Identifier;
			}
			void set(Guid value)
			{
				this->m_Identifier = value;
			}
		}
		property GetVirtualDiskInfoParentLocation ParentLocation
		{
			GetVirtualDiskInfoParentLocation get()
			{
				return this->m_ParentLocation;
			}
			void set(GetVirtualDiskInfoParentLocation value)
			{
				this->m_ParentLocation = value;
			}
		}
		property Guid ParentIdentifier
		{
			Guid get()
			{
				return this->m_ParentIdentifier;
			}
			void set(Guid value)
			{
				this->m_ParentIdentifier = value;
			}
		}
		property unsigned long ParentTimestamp
		{
			unsigned long get()
			{
				return this->m_ParentTimestamp;
			}
			void set(unsigned long value)
			{
				this->m_ParentTimestamp = value;
			}
		}
		property _VirtualStorageType VirtualStorageType
		{
			_VirtualStorageType get()
			{
				return this->m_VirtualStorageType;
			}
			void set(_VirtualStorageType value)
			{
				this->m_VirtualStorageType = value;
			}
		}
		property unsigned long ProviderSubtype
		{
			unsigned long get()
			{
				return this->m_ProviderSubtype;
			}
			void set(unsigned long value)
			{
				this->m_ProviderSubtype = value;
			}
		}
		property bool Is4kAligned
		{
			bool get()
			{
				return this->m_Is4kAligned;
			}
			void set(bool value)
			{
				this->m_Is4kAligned = value;
			}
		}
		property bool IsLoaded
		{
			bool get()
			{
				return this->m_IsLoaded;
			}
			void set(bool value)
			{
				this->m_IsLoaded = value;
			}
		}
		property GetVirtualDiskInfoPhysicalDisk PhysicalDisk
		{
			GetVirtualDiskInfoPhysicalDisk get()
			{
				return this->m_PhysicalDisk;
			}
			void set(GetVirtualDiskInfoPhysicalDisk value)
			{
				this->m_PhysicalDisk = value;
			}
		}
		property unsigned long VhdPhysicalSectorSize
		{
			unsigned long get()
			{
				return this->m_VhdPhysicalSectorSize;
			}
			void set(unsigned long value)
			{
				this->m_VhdPhysicalSectorSize = value;
			}
		}
		property unsigned long long SmallestSafeVirtualSize
		{
			unsigned long long get()
			{
				return this->m_SmallestSafeVirtualSize;
			}
			void set(unsigned long long value)
			{
				this->m_SmallestSafeVirtualSize = value;
			}
		}
		property unsigned long FragmentationPercentage
		{
			unsigned long get()
			{
				return this->m_FragmentationPercentage;
			}
			void set(unsigned long value)
			{
				this->m_FragmentationPercentage = value;
			}
		}
		property Guid VirtualDiskId
		{
			Guid get()
			{
				return this->m_VirtualDiskId;
			}
			void set(Guid value)
			{
				this->m_VirtualDiskId = value;
			}
		}
#ifdef WIN10SUPPORT
		property GetVirtualDiskInfoChangeTrackingState ChangeTrackingState
		{
			GetVirtualDiskInfoChangeTrackingState get()
			{
				return this->m_ChangeTrackingState;
			}
			void set(GetVirtualDiskInfoChangeTrackingState value)
			{
				this->m_ChangeTrackingState = value;
			}
		}
#endif
	private:
		GetVirtualDiskInfoVersions m_Version;
		GetVirtualDiskInfoSize m_Size;
		Guid m_Identifier;
		GetVirtualDiskInfoParentLocation m_ParentLocation;
		Guid m_ParentIdentifier;
		unsigned long m_ParentTimestamp;
		_VirtualStorageType m_VirtualStorageType;
		unsigned long m_ProviderSubtype;
		bool m_Is4kAligned;
		bool m_IsLoaded;
		GetVirtualDiskInfoPhysicalDisk m_PhysicalDisk;
		unsigned long m_VhdPhysicalSectorSize;
		unsigned long long m_SmallestSafeVirtualSize;
		unsigned long m_FragmentationPercentage;
		Guid m_VirtualDiskId;
#ifdef WIN10SUPPORT
		GetVirtualDiskInfoChangeTrackingState m_ChangeTrackingState;
#endif
	};
}