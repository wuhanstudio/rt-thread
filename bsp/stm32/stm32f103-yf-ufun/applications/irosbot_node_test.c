/*
 * @Description: test node
 * @Author: your name
 * @Date: 2019-07-21 12:35:48
 * @LastEditTime: 2019-07-21 20:08:53
 * @LastEditors: Please set LastEditors
 */

#include "node.h"

void update_1(void* num)
{
    rt_kprintf("node 1 received %d\n", *(int*)num);
}

void exec_1(void* dev, rt_uint8_t cmd, void* args)
{
    rt_kprintf("node 1 execute cmd %d\n", cmd);
}

void update_2(void* num)
{
    rt_kprintf("node 2 received %d\n", *(int*)num);
}

void exec_2(void* dev, rt_uint8_t cmd, void* args)
{
    rt_kprintf("node 2 execute cmd %d\n", cmd);
}

void update_3(void* num)
{
    rt_kprintf("node 3 received %d\n", *(int*)num);
}

void exec_3(void* dev, rt_uint8_t cmd, void* args)
{
    rt_kprintf("node 3 execute cmd %d\n", cmd);
}

void irosbot_node_test(int argc, char *argv[])
{
    node_t node1 = node_create(update_1, exec_1);
    node_t node2 = node_create(update_2, exec_2);
    node_t node3 = node_create(update_3, exec_3);

    node_attach(node1, node2);
    node_attach(node1, node3);

    int* msg = (int*) rt_malloc(sizeof(int));
    *msg = 20;
    rt_kprintf("node 1 publish msg %d\n", *msg);
    node_update(node1, msg);

    rt_kprintf("Detach node 2\n");
    node_detach(node1, node2);
    *msg = 30;
    rt_kprintf("node 1 publish msg %d\n", *msg);
    node_update(node1, msg);

    rt_kprintf("Detach node 3\n");
    node_detach(node1, node3);
    *msg = 40;
    rt_kprintf("node 1 publish msg %d\n", *msg);
    node_update(node1, msg);
}
MSH_CMD_EXPORT(irosbot_node_test, irosbot node test);
