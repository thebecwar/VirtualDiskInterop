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

		LPWSTR m_NativeParentFilePath = NULL;
	internal:
		void PopulateNativeStruct(SET_VIRTUAL_DISK_INFO* info)
		{
			this->ReleaseNativeData();

			info->ParentPathWithDepthInfo.ChildDepth = this->m_ChildDepth;
			this->m_NativeParentFilePath = Helpers::AllocString(this->m_ParentFilePath);
			info->ParentPathWithDepthInfo.ParentFilePath = this->m_NativeParentFilePath;
		}
		void ReadNativeStruct(SET_VIRTUAL_DISK_INFO* info)
		{
			this->m_ChildDepth = info->ParentPathWithDepthInfo.ChildDepth;
			this->m_ParentFilePath = gcnew String(info->ParentPathWithDepthInfo.ParentFilePath);
			this->ReleaseNativeData();
		}
		void ReleaseNativeData()
		{
			if (this->m_NativeParentFilePath)
			{
				LocalFree(this->m_NativeParentFilePath);
				this->m_NativeParentFilePath = NULL;
			}
		}
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

		LPWSTR m_NativeParentFilePath = NULL;
	internal:
		void PopulateNativeStruct(SET_VIRTUAL_DISK_INFO* info)
		{
			info->ParentLocator.LinkageId = Helpers::ToGUID(this->m_LinkageId);
			this->m_NativeParentFilePath = Helpers::AllocString(this->m_ParentFilePath);
			info->ParentLocator.ParentFilePath = this->m_NativeParentFilePath;
		}
		void ReadNativeStruct(SET_VIRTUAL_DISK_INFO* info)
		{
			this->m_LinkageId = Helpers::FromGUID(info->ParentLocator.LinkageId);
			this->m_ParentFilePath = gcnew String(info->ParentLocator.ParentFilePath);
			this->ReleaseNativeData();
		}
		void ReleaseNativeData()
		{
			if (this->m_NativeParentFilePath)
			{
				LocalFree(this->m_NativeParentFilePath);
				this->m_NativeParentFilePath = NULL;
			}
		}
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
		LPWSTR m_NativeParentFilePath = NULL;
	internal:
		SET_VIRTUAL_DISK_INFO* m_NativeData = NULL;
		SET_VIRTUAL_DISK_INFO* GetNative()
		{
			this->ReleaseNative(false);
			this->m_NativeData = new SET_VIRTUAL_DISK_INFO();
			this->m_NativeData->Version = (SET_VIRTUAL_DISK_INFO_VERSION)this->m_Version;
			switch (this->m_Version)
			{
			case SetVirtualDiskInfoVersions::ParentPath:
				this->m_NativeParentFilePath = Helpers::AllocString(this->m_ParentFilePath);
				this->m_NativeData->ParentFilePath = this->m_NativeParentFilePath;
				break;
			case SetVirtualDiskInfoVersions::Identifier:
				this->m_NativeData->UniqueIdentifier = Helpers::ToGUID(this->m_UniqueIdentifier);
				break;
			case SetVirtualDiskInfoVersions::ParentPathWithDepth:
				this->m_ParentPathWithDepthInfo.PopulateNativeStruct(this->m_NativeData);
				break;
			case SetVirtualDiskInfoVersions::PhysicalSectorSize:
				this->m_NativeData->VhdPhysicalSectorSize = this->m_VhdPhysicalSectorSize;
				break;
			case SetVirtualDiskInfoVersions::VirtualDiskID:
				this->m_NativeData->VirtualDiskId = Helpers::ToGUID(this->m_VirtualDiskId);
				break;
#ifdef WIN10SUPPORT
			case SetVirtualDiskInfoVersions::ChangeTrackingState:
				this->m_NativeData->ChangeTrackingEnabled = (BOOL)this->m_ChangeTrackingEnabled;
				break;
			case SetVirtualDiskInfoVersions::ParentLocation:
				this->m_ParentLocator.PopulateNativeStruct(this->m_NativeData);
				break;
#endif
			}
			return this->m_NativeData;
		}
		void ReleaseNative(bool updateData)
		{
			if (this->m_NativeData)
			{
				if (updateData)
				{
					this->m_NativeData->Version = (SET_VIRTUAL_DISK_INFO_VERSION)this->m_Version;
					switch (this->m_Version)
					{
					case SetVirtualDiskInfoVersions::ParentPath:
						this->m_ParentFilePath = gcnew String(this->m_NativeData->ParentFilePath);
						break;
					case SetVirtualDiskInfoVersions::Identifier:
						this->m_UniqueIdentifier = Helpers::FromGUID(this->m_NativeData->UniqueIdentifier);
						break;
					case SetVirtualDiskInfoVersions::ParentPathWithDepth:
						this->m_ParentPathWithDepthInfo.ReadNativeStruct(this->m_NativeData);
						break;
					case SetVirtualDiskInfoVersions::PhysicalSectorSize:
						this->m_VhdPhysicalSectorSize = this->m_NativeData->VhdPhysicalSectorSize;
						break;
					case SetVirtualDiskInfoVersions::VirtualDiskID:
						this->m_VirtualDiskId = Helpers::FromGUID(this->m_NativeData->VirtualDiskId);
						break;
#ifdef WIN10SUPPORT
					case SetVirtualDiskInfoVersions::ChangeTrackingState:
						this->m_ChangeTrackingEnabled = this->m_NativeData->ChangeTrackingEnabled != 0;
						break;
					case SetVirtualDiskInfoVersions::ParentLocation:
						this->m_ParentLocator.ReadNativeStruct(this->m_NativeData);
						break;
#endif
					}
				}
				delete this->m_NativeData;
				this->m_NativeData = NULL;
			}
			this->m_ParentPathWithDepthInfo.ReleaseNativeData();
			this->m_ParentLocator.ReleaseNativeData();
			if (this->m_NativeParentFilePath)
			{
				LocalFree(this->m_NativeParentFilePath);
				this->m_NativeParentFilePath = NULL;
			}
			
		}
	};
}