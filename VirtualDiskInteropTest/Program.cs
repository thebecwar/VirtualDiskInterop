using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

using VirtualDiskInterop;

namespace VirtualDiskInteropTest
{
    class Program
    {
        static void Main(string[] args)
        {
            VirtualStorageType storageType = new VirtualStorageType();
            storageType.DeviceId = VirtualStorageDeviceTypes.Vhdx;
            storageType.VendorId = VirtualStorageType.VendorIdMicrosoft;

            VirtualDiskSafeHandle diskHandle = new VirtualDiskSafeHandle();

            string filename = @"";
            
            OpenVirtualDiskParameters readParameters = new OpenVirtualDiskParameters();
            readParameters.Version = OpenVirtualDiskVersions.Version1;
            
            uint result = VirtualDiskApi.OpenVirtualDisk(storageType, 
                                                         filename, 
                                                         VirtualDiskAccessMasks.All, 
                                                         OpenVirtualDiskFlags.None, 
                                                         readParameters, 
                                                         diskHandle);

            Guid customMetadata = Guid.NewGuid();
            Guid[] metadataIds = null;
            byte[] metaData = null;

            result = VirtualDiskApi.EnumerateVirtualDiskMetadata(diskHandle, out metadataIds);

            result = VirtualDiskApi.GetVirtualDiskMetadata(diskHandle, customMetadata, out metaData);

            metaData = new byte[] { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05 };
            result = VirtualDiskApi.SetVirtualDiskMetadata(diskHandle, customMetadata, metaData);

            result = VirtualDiskApi.EnumerateVirtualDiskMetadata(diskHandle, out metadataIds);

            result = VirtualDiskApi.GetVirtualDiskMetadata(diskHandle, customMetadata, out metaData);

            result = VirtualDiskApi.DeleteVirtualDiskMetadata(diskHandle, customMetadata);

            result = VirtualDiskApi.GetVirtualDiskMetadata(diskHandle, customMetadata, out metaData);



            string path = "";
            result = VirtualDiskApi.GetVirtualDiskPhysicalPath(diskHandle, out path);

            GetVirtualDiskInfo info = new GetVirtualDiskInfo();
            info.Version = GetVirtualDiskInfoVersions.Size;

            result = VirtualDiskApi.GetVirtualDiskInformation(diskHandle, ref info);



            diskHandle.ReleaseHandle();
            diskHandle = null;
        }
    }
}
