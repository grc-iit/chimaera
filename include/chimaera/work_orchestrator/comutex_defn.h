//
// Created by llogan on 4/8/24.
//

#ifndef CHIMAERA_INCLUDE_CHIMAERA_WORK_ORCHESTRATOR_COMUTEX_DEFN_H_
#define CHIMAERA_INCLUDE_CHIMAERA_WORK_ORCHESTRATOR_COMUTEX_DEFN_H_

#include "chimaera/task_registry/task.h"

namespace chi {

struct CoMutexEntry {
  Task *task_;
};

/** A mutex for yielding coroutines */
class CoMutex {
 public:
  typedef std::vector<CoMutexEntry> COMUTEX_QUEUE_T;

 public:
  TaskId root_;
  size_t rep_;
  std::unordered_map<TaskId, COMUTEX_QUEUE_T> blocked_map_;

 public:
  CoMutex() {
    root_.SetNull();
    rep_ = 0;
  }

  void Lock();

  void Unlock();
};

class ScopedCoMutex {
 public:
  CoMutex &mutex_;

 public:
  ScopedCoMutex(CoMutex &mutex)
      : mutex_(mutex) {
    mutex_.Lock();
  }

  ~ScopedCoMutex() {
    mutex_.Unlock();
  }
};

}  // namespace chi

#endif  // CHIMAERA_INCLUDE_CHIMAERA_WORK_ORCHESTRATOR_COMUTEX_DEFN_H_
