//
// Created by lukemartinlogan on 6/29/23.
//

#ifndef HRUN_worch_proc_round_robin_H_
#define HRUN_worch_proc_round_robin_H_

#include "worch_proc_round_robin_tasks.h"

namespace chm::worch_proc_round_robin {

/** Create admin requests */
class Client : public TaskLibClient {

 public:
  /** Default constructor */
  Client() = default;

  /** Destructor */
  ~Client() = default;

  /** Create a worch_proc_round_robin */
  HSHM_ALWAYS_INLINE
  void CreateRoot(const DomainId &domain_id,
                  const std::string &state_name) {
    id_ = TaskStateId::GetNull();
    std::vector<PriorityInfo> queue_info;
    id_ = CHM_ADMIN->CreateTaskStateRoot<ConstructTask>(
        domain_id, state_name, id_, queue_info);
  }

  /** Destroy state */
  HSHM_ALWAYS_INLINE
  void DestroyRoot(const DomainId &domain_id) {
    CHM_ADMIN->DestroyTaskStateRoot(domain_id, id_);
  }
};

}  // namespace chm

#endif  // HRUN_worch_proc_round_robin_H_
