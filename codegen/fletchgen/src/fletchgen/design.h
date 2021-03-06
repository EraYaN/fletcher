// Copyright 2018 Delft University of Technology
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <arrow/api.h>
#include <cerata/api.h>
#include <fletcher/common.h>

#include <deque>
#include <memory>
#include <vector>

#include "fletchgen/schema.h"
#include "fletchgen/options.h"
#include "fletchgen/kernel.h"
#include "fletchgen/mantle.h"
#include "fletchgen/bus.h"
#include "fletchgen/recordbatch.h"

namespace fletchgen {

/// A structure for all components in a Fletcher design.
struct Design {
  /// Make a new Design structure based on program options.
  static Design GenerateFrom(const std::shared_ptr<Options> &opts);

  /// The program options.
  std::shared_ptr<Options> options;

  /// The SchemaSet to base the design on.
  std::shared_ptr<SchemaSet> schema_set;

  /// The RecordBatchDescriptions to use in SREC generation.
  std::vector<fletcher::RecordBatchDescription> batch_desc;

  /// The RecordBatch(Readers/Writers) in the design.
  std::deque<std::shared_ptr<Component>> recordbatches;
  /// The Kernel component of this design.
  std::shared_ptr<Kernel> kernel;

  /// The top-level wrapper (mantle) of the design. This is not called wrapper because this is reserved for future top
  /// levels that instantiate multiple mantles to operate in parallel.
  std::shared_ptr<Mantle> mantle;

  /// Obtain a Cerata OutputSpec from this design for Cerata back-ends to generate output.
  std::deque<cerata::OutputSpec> GetOutputSpec();
};

}  // namespace fletchgen
