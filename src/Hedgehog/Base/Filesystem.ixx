#include <vector>
#include <string>

#include <hedgelib/archives/hl_archive.h>

export module Hedgehog.Base.FileSystem;

export namespace Hedgehog
{
    export namespace Base
    {
        export class CFileSystem
        {
            //void AddFileSystem(IFileSystemProvider* provider, std::string root);
        };

        export class IFileSystemProvider
        {

        };

        export class CFileSystemProvider
        {
            //  std::vector<CFile*> 
        };

        export class CFile
        {
            CFileSystemProvider* m_pProvider;
        };
    }
}