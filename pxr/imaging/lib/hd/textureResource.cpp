//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#include "pxr/imaging/hd/textureResource.h"
#include "pxr/imaging/hd/perfLog.h"
#include "pxr/base/tf/staticTokens.h"

PXR_NAMESPACE_OPEN_SCOPE


TF_DEFINE_PRIVATE_TOKENS(
    _tokens,

    ((fallbackPtexPath, "PtExNoNsEnSe"))
    ((fallbackUVPath, "UvNoNsEnSe"))
);

HdTextureResource::~HdTextureResource()
{
}

/* static */
HdTextureResource::ID
HdTextureResource::ComputeHash(TfToken const &sourceFile)
{
    HD_TRACE_FUNCTION();

    uint32_t hash = 0;
    std::string const &filename = sourceFile.GetString();
    hash = ArchHash(filename.c_str(), filename.size(), hash);

    return hash;
}

/* static */
HdTextureResource::ID
HdTextureResource::ComputeFallbackPtexHash()
{
    HD_TRACE_FUNCTION();

    uint32_t hash = 0;
    std::string const &filename = _tokens->fallbackPtexPath.GetString();
    hash = ArchHash(filename.c_str(), filename.size(), hash);

    return hash;
}

/* static */
HdTextureResource::ID
HdTextureResource::ComputeFallbackUVHash()
{
    HD_TRACE_FUNCTION();

    uint32_t hash = 0;
    std::string const &filename = _tokens->fallbackUVPath.GetString();
    hash = ArchHash(filename.c_str(), filename.size(), hash);

    return hash;
}

PXR_NAMESPACE_CLOSE_SCOPE

