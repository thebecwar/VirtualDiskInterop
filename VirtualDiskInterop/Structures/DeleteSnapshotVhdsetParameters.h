#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	public value class DeleteSnapshotVhdsetParametersVersion1
	{
	public:
		property Guid SnapshotId
		{
			Guid get()
			{
				return this->m_SnapshotId;
			}
			void set(Guid value)
			{
				this->m_SnapshotId = value;
			}
		}
	private:
		Guid m_SnapshotId;
	};

	public value class DeleteSnapshotVhdsetParameters
	{
	public:
		property DeleteSnapshotVhdsetVersions Version
		{
			DeleteSnapshotVhdsetVersions get()
			{
				return this->m_Version;
			}
			void set(DeleteSnapshotVhdsetVersions value)
			{
				this->m_Version = value;
			}
		}
		property DeleteSnapshotVhdsetParametersVersion1 Version1
		{
			DeleteSnapshotVhdsetParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(DeleteSnapshotVhdsetParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
	private:
		DeleteSnapshotVhdsetVersions m_Version;
		DeleteSnapshotVhdsetParametersVersion1 m_Version1;
	};
#endif
}