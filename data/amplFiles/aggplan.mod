param wage_rate;
param overtime_premium;
param max_overtime;
param start_inv;
param end_inv;
param output_rate;
param start_work_force;
param safety_stock >= 0;
param inv_unit_cost >= 0;
param hiring_cost;
param firing_cost;

set periods ordered;

param demand {periods} >= 0;

var number_workers {periods} >=0, integer;
var overtime {periods} >= 0;
var workers_hired {periods} >= 0;
var workers_fired {periods} >= 0;
var inventory {periods} >= safety_stock;

minimize total_cost: sum{i in periods} (wage_rate*number_workers[i]
                 +(overtime_premium)*wage_rate*overtime[i]
                 + hiring_cost*workers_hired[i]
                 + firing_cost*workers_fired[i]
                 + inv_unit_cost*inventory[i]);

s.t. inv_balance{i in periods}: inventory[i] = output_rate*(number_workers[i] + overtime[i])
                                               - demand[i]
                                               + if (i = first(periods)) then start_inv
                                                                         else inventory[prev(i)];

s.t. overtime_limit{i in periods}: overtime[i] <= max_overtime*number_workers[i];

s.t. workforce_balance{i in periods}:
                   if (i = first(periods)) then start_work_force else number_workers[prev(i)]
                   + workers_hired[i] - workers_fired[i] = number_workers[i];

s.t. end_inventory: inventory[last(periods)] = end_inv;  
