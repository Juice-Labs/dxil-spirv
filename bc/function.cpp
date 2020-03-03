/*
 * Copyright 2019-2020 Hans-Kristian Arntzen for Valve Corporation
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

#include "function.hpp"
#include "module.hpp"
#include "context.hpp"
#include "type.hpp"

namespace LLVMBC
{
Function::Function(FunctionType *function_type_, uint64_t value_id_, Module &module_)
	: Value(function_type_->getReturnType(), ValueKind::Function),
	value_id(value_id_), module(module_), function_type(function_type_)
{
}

const std::string &Function::getName() const
{
	return module.get_value_name(value_id);
}

void Function::set_basic_blocks(std::vector<BasicBlock *> basic_blocks_)
{
	basic_blocks = std::move(basic_blocks_);
}

FunctionType *Function::getFunctionType() const
{
	return function_type;
}

std::vector<BasicBlock *>::const_iterator Function::begin() const
{
	return basic_blocks.begin();
}

std::vector<BasicBlock *>::const_iterator Function::end() const
{
	return basic_blocks.end();
}

BasicBlock::BasicBlock(LLVMContext &context_)
	: context(context_)
{
}

void BasicBlock::add_instruction(Instruction *inst)
{
	instructions.push_back(inst);
}

std::vector<Instruction *>::const_iterator BasicBlock::begin() const
{
	return instructions.begin();
}

std::vector<Instruction *>::const_iterator BasicBlock::end() const
{
	return instructions.end();
}
}
