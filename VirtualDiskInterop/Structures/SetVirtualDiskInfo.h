#pragma once

using namespace System;

namespace VirtualDiskInterop
{
	public value class SetVirtualDiskInfoParentPathWithDepthInfo
	{
	public:
		property unsigned long ChildDepth
		{
			unsigned long get()
			{
				return this->m_ChildDepth;
			}
			void set(unsigned long value)
			{
				this->m_ChildDepth = value;
			}
		}
		property String^ ParentFilePath
		{
			String^ get()
			{
				return this->m_ParentFilePath;
			}
			void set(String^ value)
			{
				this->m_ParentFilePath = value;
			}
		}
	private:
		unsigned long m_ChildDepth;
		String^ m_ParentFilePath;
	};

#ifdef WIN10SUPPORT
	public value class SetVirtualDiskInfoParentLocator
	{
	public:
		property Guid LinkageId
		{
			Guid get()
			{
				return this->m_LinkageId;
			}
			void set(Guid value)
			{
				this->m_LinkageId = value;
			}
		}
		property String^ ParentFilePath
		{
			String^ get()
			{
				return this->m_ParentFilePath;
			}
			void set(String^ value)
			{
				this->m_ParentFilePath = value;
			}
		}
	private:
		Guid m_LinkageId;
		String^ m_ParentFilePath;
	};
#endif

	public value class SetVirtualDiskInfo
	{
	public:
		property SetVirtualDiskInfoVersions Version
		{
			SetVirtualDiskInfoVersions get()
			{
				return this->m_Version;
			}
			void set(SetVirtualDiskInfoVersions value)
			{
				this->m_Version = value;
			}
		}
		property String^ ParentFilePath
		{
			String^ get()
			{
				return this->m_ParentFilePath;
			}
			void set(String^ value)
			{
				this->m_ParentFilePath = value;
			}
		}
		property Guid UniqueIdentifier
		{
			Guid get()
			{
				return this->m_UniqueIdentifier;
			}
			void set(Guid value)
			{
				this->m_UniqueIdentifier = value;
			}
		}
		property SetVirtualDiskInfoParentPathWithDepthInfo ParentPathWithDepthInfo
		{
			SetVirtualDiskInfoParentPathWithDepthInfo get()
			{
				return this->m_ParentPathWithDepthInfo;
			}
			void set(SetVirtualDiskInfoParentPathWithDepthInfo value)
			{
				this->m_ParentPathWithDepthInfo = value;
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
		property bool ChangeTrackingEnabled
		{
			bool get()
			{
				return this->m_ChangeTrackingEnabled;
			}
			void set(bool value)
			{
				this->m_ChangeTrackingEnabled = value;
			}
		}
		property SetVirtualDiskInfoParentLocator ParentLocator
		{
			SetVirtualDiskInfoParentLocator get()
			{
				return this->m_ParentLocator;
			}
			void set(SetVirtualDiskInfoParentLocator value)
			{
				this->m_ParentLocator = value;
			}
		}
#endif
	private:
		SetVirtualDiskInfoVersions m_Version;
		String^ m_ParentFilePath;
		Guid m_UniqueIdentifier;
		SetVirtualDiskInfoParentPathWithDepthInfo m_ParentPathWithDepthInfo;
		unsigned long m_VhdPhysicalSectorSize;
		Guid m_VirtualDiskId;
#ifdef WIN10SUPPORT
		bool m_ChangeTrackingEnabled;
		SetVirtualDiskInfoParentLocator m_ParentLocator;
#endif
	};
}