<!--suppress ALL -->
<template>
    <div>
        <el-row :gutter="20" type="flex" align="middle">
            <el-col :span="6">
                <h3>
                    Advertisement List
                </h3>
            </el-col>
            <el-col :span="18" :offset="4">
                <el-input placeholder="搜索" clearable v-model="filter_keyword" class="input-with-select">
                    <el-select class="el-select-width" v-model="sort_method" slot="prepend" clearable
                               placeholder="排序方式">
                        <el-option label="名称" value="name"></el-option>
                        <el-option label="发布者" value="poster"></el-option>
                        <el-option label="发布日期" value="post_date"></el-option>
                        <el-option label="结束日期" value="close_date"></el-option>
                        <el-option label="数量" value="quantity"></el-option>
                        <el-option label="投标价(升序)" value="bid_asc"></el-option>
                        <el-option label="投标价(降序)" value="bid_desc"></el-option>
                    </el-select>
                    <el-button slot="append" icon="el-icon-search"></el-button>
                </el-input>
                <el-button-group>
                    <el-button type="primary" icon="el-icon-plus" @click="add_open = true">添加</el-button>
                    <el-button type="primary" icon="el-icon-close" @click="Logout">注销</el-button>
                </el-button-group>
            </el-col>
        </el-row>
        <el-table :data="tableData" style="width: 100%;">
            <el-table-column fixed prop="title" label="名称" width="150">
            </el-table-column>
            <el-table-column prop="email" label="发布者" width="150">
            </el-table-column>
            <el-table-column prop="start" label="发布日期" width="180">
            </el-table-column>
            <el-table-column prop="close" label="结束日期" width="180">
            </el-table-column>
            <el-table-column prop="quantity" label="数量" width="120">
            </el-table-column>
            <el-table-column prop="body" label="描述" width="220">
            </el-table-column>
            <el-table-column fixed="right" label="操作" width="120">
                <template slot-scope="scope">
                    <el-button @click.native.prevent="GoBid(scope.$index, tableData)" type="text" size="small">
                        投标
                    </el-button>
                </template>
            </el-table-column>
        </el-table>
        <el-dialog title="添加" :visible.sync="add_open">
            <el-form ref="form" :model="add_form" label-width="80px">
                <el-form-item label="名称">
                    <el-input v-model="add_form.title"></el-input>
                </el-form-item>
                <el-form-item label="投递者">
                    <el-input v-model="add_form.email"></el-input>
                </el-form-item>
                <el-form-item label="起止时间">
                    <el-col :span="11">
                        <el-date-picker type="datetime" placeholder="选择开始日期" v-model="add_form.start"></el-date-picker>
                    </el-col>
                    <el-col class="line" :span="2">-</el-col>
                    <el-col :span="11">
                        <el-date-picker type="datetime" placeholder="选择结束日期" v-model="add_form.close"></el-date-picker>
                    </el-col>
                </el-form-item>
                <el-form-item label="质量">
                    <el-input type="number" v-model="add_form.quantity"></el-input>
                </el-form-item>
                <el-form-item label="介绍">
                    <el-input v-model="add_form.body"></el-input>
                </el-form-item>
            </el-form>
            <div slot="footer" style="text-align: right">
                <el-button @click="add_open = false">取 消</el-button>
                <el-button type="primary" @click="submit">确 定</el-button>
            </div>
        </el-dialog>
    </div>
</template>

<script>
    export default {
        name: "DataTable",
        data() {
            return {
                tableData: [],
                sort_method: "",
                filter_keyword: "",
                add_open: false,
                add_form: {
                    quantity: 0, title: "", email: "", body: "", start: "", close: ""
                }
            }
        },
        methods: {
            async Logout() {
                let response = await this.axios.post("/api/logout").catch(_ => {
                });
                if ("status" in response.data && response.data.status) {
                    this.$message({
                        showClose: true,
                        message: '注销成功',
                        type: 'success'
                    });
                    this.$store.commit("changeLoginStatus", true)
                    this.$nextTick(() => {
                        this.$router.push("/exercise/login")
                    })
                } else {
                    this.$message({
                        showClose: true,
                        message: '注销失败',
                        type: 'error'
                    });
                    this.login.email = "";
                    this.login.password = "";
                }
            },
            async RequestList() {
                let response = await this.axios.post("/api/list").catch(_ => this.tableData = []);
                if (response.length === 0) {
                    this.tableData = []
                } else {
                    let data = response.data
                    data.forEach(item => {
                        item.start = this.getDate(item.start)
                        item.close = this.getDate(item.close)
                    })
                    this.tableData = response.data;
                }
            },
            getDateTimeStruct(date) {
                console.log(date)
                if (!(date instanceof Date)){
                    date = new Date(date)
                }
                return {
                    "year": date.getFullYear(),
                    "month": date.getMonth() + 1,
                    "day": date.getDay(),
                    "hour": date.getHours(),
                    "minute": date.getMinutes(),
                    "second": date.getSeconds()
                };
            },
            getDate(obj) {
                let date = new Date(obj.year, obj.month - 1, obj.day)
                date.setHours(obj.hour, obj.minute, obj.second)
                return date.toLocaleDateString() + date.toLocaleTimeString()
            },
            async submit() {
                let data = JSON.parse(JSON.stringify(this.add_form))
                data.start = this.getDateTimeStruct(data.start)
                data.close = this.getDateTimeStruct(data.close)
                data.quantity = Number.parseInt(data.quantity)
                let response = await this.axios.post("/api/list/add", data).catch(_ => {
                });
                this.add_form = {
                    quantity: 0, title: "", email: "", body: "", start: "", close: ""
                }
                await this.RequestList()
                this.add_open = false
            }
        },
        mounted() {
            // if (!this.$store.state.loginStatus) {
            //     this.$message({
            //         showClose: true,
            //         message: '你还没有登录= =',
            //         type: 'error'
            //     });
            //     this.$router.push('/exercise/login')
            // }
            this.RequestList();
        }
    }
</script>

<style scoped>
    .el-select-width {
        width: 130px;
    }

    .input-with-select {
        background-color: #fff;
        width: 70%;
    }
</style>