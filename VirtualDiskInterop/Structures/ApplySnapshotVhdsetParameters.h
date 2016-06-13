#pragma once

using namespace System;

namespace VirtualDiskInterop
{
#ifdef WIN10SUPPORT
	value class ApplySnapshotVhdsetParametersVersion1
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
		property Guid LeafSnapshotId
		{
			Guid get()
			{
				return this->m_LeafSnapshotId;
			}
			void set(Guid value)
			{
				this->m_LeafSnapshotId = value;
			}
		}
	private:
		Guid m_SnapshotId;
		Guid m_LeafSnapshotId;
	};
	public value class ApplySnapshotVhdsetParameters
	{
	public:
		property ApplySnapshotVhdsetVersions Version
		{
			ApplySnapshotVhdsetVersions get()
			{
				return this->m_Version;
			}
			void set(ApplySnapshotVhdsetVersions value)
			{
				this->m_Version = value;
			}
		}
		property ApplySnapshotVhdsetParametersVersion1 Version1
		{
			ApplySnapshotVhdsetParametersVersion1 get()
			{
				return this->m_Version1;
			}
			void set(ApplySnapshotVhdsetParametersVersion1 value)
			{
				this->m_Version1 = value;
			}
		}
	private:
		ApplySnapshotVhdsetVersions m_Version;
		ApplySnapshotVhdsetParametersVersion1 m_Version1;
	};
#endif
}