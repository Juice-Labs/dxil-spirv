/*
 * Copyright 2019 Hans-Kristian Arntzen for Valve Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#pragma once
#include "opcodes/opcodes.hpp"

namespace DXIL2SPIRV
{
bool emit_discard_instruction(std::vector<Operation> &ops, Converter::Impl &impl, spv::Builder &builder,
                              const llvm::CallInst *instruction);

bool emit_derivative_instruction(spv::Op opcode, std::vector<Operation> &ops, Converter::Impl &impl, spv::Builder &builder,
                                 const llvm::CallInst *instruction);

template <spv::Op opcode>
static inline bool emit_derivative_dispatch(std::vector<Operation> &ops, Converter::Impl &impl, spv::Builder &builder,
                                            const llvm::CallInst *instruction)
{
	return emit_derivative_instruction(opcode, ops, impl, builder, instruction);
}
}