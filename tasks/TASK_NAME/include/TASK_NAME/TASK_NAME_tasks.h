//
// Created by lukemartinlogan on 8/11/23.
//

#ifndef HRUN_TASKS_TASK_TEMPL_INCLUDE_TASK_NAME_TASK_NAME_TASKS_H_
#define HRUN_TASKS_TASK_TEMPL_INCLUDE_TASK_NAME_TASK_NAME_TASKS_H_

#include "chimaera/api/chimaera_client.h"
#include "chimaera/task_registry/task_lib.h"
#include "chimaera_admin/chimaera_admin.h"
#include "chimaera/queue_manager/queue_manager_client.h"

namespace chm::TASK_NAME {

#include "TASK_NAME_methods.h"
#include "chimaera/chimaera_namespace.h"

/**
 * A task to create TASK_NAME
 * */
using chm::Admin::CreateTaskStateTask;
struct CreateTask : public CreateTaskStateTask {
  /** SHM default constructor */
  HSHM_ALWAYS_INLINE explicit
  CreateTask(hipc::Allocator *alloc)
  : CreateTaskStateTask(alloc) {}

  /** Emplace constructor */
  HSHM_ALWAYS_INLINE explicit
  CreateTask(hipc::Allocator *alloc,
                const TaskNode &task_node,
                const DomainQuery &dom_query,
                const std::string &state_name,
                const TaskStateId &id)
      : CreateTaskStateTask(alloc, task_node, dom_query, state_name,
                            "TASK_NAME", id) {
    // Custom params
  }

  HSHM_ALWAYS_INLINE
  ~CreateTask() {
    // Custom params
  }
};

/** A task to destroy TASK_NAME */
using chm::Admin::DestroyTaskStateTask;
struct DestructTask : public DestroyTaskStateTask {
  /** SHM default constructor */
  HSHM_ALWAYS_INLINE explicit
  DestructTask(hipc::Allocator *alloc)
  : DestroyTaskStateTask(alloc) {}

  /** Emplace constructor */
  HSHM_ALWAYS_INLINE explicit
  DestructTask(hipc::Allocator *alloc,
               const TaskNode &task_node,
               const DomainQuery &dom_query,
               TaskStateId &state_id)
  : DestroyTaskStateTask(alloc, task_node, dom_query, state_id) {}
};

/**
 * A custom task in TASK_NAME
 * */
struct CustomTask : public Task, TaskFlags<TF_SRL_SYM> {
  /** SHM default constructor */
  HSHM_ALWAYS_INLINE explicit
  CustomTask(hipc::Allocator *alloc) : Task(alloc) {}

  /** Emplace constructor */
  HSHM_ALWAYS_INLINE explicit
  CustomTask(hipc::Allocator *alloc,
             const TaskNode &task_node,
             const DomainQuery &dom_query,
             const TaskStateId &state_id) : Task(alloc) {
    // Initialize task
    task_node_ = task_node;
    prio_ = TaskPrio::kLowLatency;
    task_state_ = state_id;
    method_ = Method::kCustom;
    task_flags_.SetBits(0);
    dom_query_ = dom_query;

    // Custom params
  }

  /** Duplicate message */
  void CopyStart(CustomTask &other, bool deep) {
  }

  /** (De)serialize message call */
  template<typename Ar>
  void SerializeStart(Ar &ar) {
  }

  /** (De)serialize message return */
  template<typename Ar>
  void SerializeEnd(Ar &ar) {
  }
};

}  // namespace chm::TASK_NAME

#endif  // HRUN_TASKS_TASK_TEMPL_INCLUDE_TASK_NAME_TASK_NAME_TASKS_H_
