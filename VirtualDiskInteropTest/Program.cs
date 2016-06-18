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
                                                         VirtualDiskAccessMasks.Read, 
                                                         OpenVirtualDiskFlags.None, 
                                                         readParameters, 
                                                         diskHandle);

            string path = "";
            result = VirtualDiskApi.GetVirtualDiskPhysicalPath(diskHandle, ref path);

            GetVirtualDiskInfo info = new GetVirtualDiskInfo();
            info.Version = GetVirtualDiskInfoVersions.Size;

            result = VirtualDiskApi.GetVirtualDiskInformation(diskHandle, ref info);



            diskHandle.ReleaseHandle();
            diskHandle = null;
        }
    }
}
