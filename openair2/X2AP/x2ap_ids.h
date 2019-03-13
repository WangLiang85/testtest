/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

#ifndef X2AP_IDS_H_
#define X2AP_IDS_H_

#define X2AP_MAX_IDS	16

typedef struct {
  int rnti;             /* -1 when free */
  int id_source;
  int id_target;
} x2ap_id;

typedef struct {
  x2ap_id ids[X2AP_MAX_IDS];
} x2ap_id_manager;

void x2ap_id_manager_init(x2ap_id_manager *m);
int x2ap_allocate_new_id(x2ap_id_manager *m);
void x2ap_release_id(x2ap_id_manager *m, int id);
int x2ap_find_id(x2ap_id_manager *, int id_source, int id_target);
int x2ap_find_id_from_rnti(x2ap_id_manager *, int rnti);
void x2ap_set_ids(x2ap_id_manager *m, int ue_id, int rnti, int id_source, int id_target);
int x2ap_id_get_id_source(x2ap_id_manager *m, int ue_id);
int x2ap_id_get_id_target(x2ap_id_manager *m, int ue_id);
int x2ap_id_get_rnti(x2ap_id_manager *m, int ue_id);

#endif /* X2AP_IDS_H_ */