// using namespace apsara;
// using namespace apsara::odps;
// using namespace apsara::odps::meta;
//
// using namespace std;
// using namespace testing;
// namespace {
//     apsara::logging::Logger* logger = apsara::logging::GetLogger("/apsara/odps/syd_json");
// }
//
// struct SydStruct: public apsara::Jsonizable
// {
//     /* data */
//     string name;
//     SydStruct(){}
//     void Jsonize(JsonWrapper& json) // NOLIN
//     {
//         // if (json.GetMode() == Jsonizable::FROM_JSON) {
//         //     int billingMethodCode = 0;
//         //     json.Jsonize(kBillingMethodKey, billingMethodCode);
//         //     mBillingMethod = static_cast<BillingMethod>(billingMethodCode);
//         // } else if (json.GetMode() == Jsonizable::TO_JSON) {
//         //     int billingMethodCode = static_cast<int>(mBillingMethod);
//         //     json.Jsonize(kBillingMethodKey, billingMethodCode);
//         // }
//         json.Jsonize("name", name, "");
//     }
//
// };
//
//
// class Stop_FuxiJob_Test : public ::testing::Test
// {
// public:
//     string json_str;
//     string four_tenant;
//     json::JsonMap input;
//
//     static void SetUpTestCase()
//     {
//         apsara::logging::InitLoggingSystem();
//     }
//
//     // static void TearDownTestCase()
//     // {
//     //     UninitLoggingSystem();
//     // }
//
//     Stop_FuxiJob_Test(){
//         json_str = "{\"one\":{\"name\":\"sun\"}, \
//         \"two\":{ \"name\":\"hu\"} }";
//
//         four_tenant = "{ \
//         \"0\": {\"CreateTime\": 1623852426,     \"Name\": \"aliyun_0\",     \"OwnerId\": \"owner_0\",     \"State\": \"NORMAL\",     \"TenantId\": \"tenant_0\",     \"TenantMeta\": \"Tenant0\",     \"UpdateTime\": 1623852426}, \
//         \"1\": {     \"CreateTime\": 1623852426,     \"Name\": \"aliyun_1\",     \"OwnerId\": \"owner_1\",     \"State\": \"NORMAL\",     \"TenantId\": \"tenant_1\",     \"TenantMeta\": \"Tenant1\",     \"UpdateTime\": 1623852426}, \
//         \"word_transformation_bad.txt\": {     \"CreateTime\": 1623852426,     \"Name\": \"aliyun_2\",     \"OwnerId\": \"owner_2\",     \"State\": \"NORMAL\",     \"TenantId\": \"tenant_2\",     \"TenantMeta\": \"Tenant2\",     \"UpdateTime\": 1623852426}, \
//         \"3\": {     \"CreateTime\": 1623852426,     \"Name\": \"aliyun_3\",     \"OwnerId\": \"owner_3\",     \"State\": \"NORMAL\",     \"TenantId\": \"tenant_3\",     \"TenantMeta\": \"Tenant3\",     \"UpdateTime\": 1623852426}, \
//         \"4\": {     \"CreateTime\": 1623852426,     \"Name\": \"aliyun_4\",     \"OwnerId\": \"owner_4\",     \"State\": \"NORMAL\",     \"TenantId\": \"tenant_4\",    \"TenantMeta\": \"Tenant4\",     \"UpdateTime\": 1623852426} }";
//
//     }
//
//     // 解析json,存到fuxiUserDefineTags里面
//     void GetSydStructFromParam(const string& param)
//     {
//         map<string,SydStruct> sydStructMap;
//         FromJsonString(sydStructMap, param);
//         cout << "size: " << sydStructMap.size() << endl;
//         map<string,SydStruct>::const_iterator it = sydStructMap.begin();
//         for(; it != sydStructMap.end(); it++)
//         {
//             cout << "it->first: " << it->first << " " ;
//             cout << it->second.name << endl;
//             // 哪里引入的？framework/quota/quota_manager.cpp
//             cout << "ToJsonCompactString: " << ToJsonCompactString(it->second.name) << endl;
//             cout << "ToJsonString: " << ToJsonString(it->second.name) << endl;
//         }
//         // size word_transformation_bad.txt
//         // it->first: onesun
//         // it->first: twohu
//     }
//
//     void GetTenantFromParam(const string& param)
//     {
//         map<string,Tenant> tenantMap;
//         FromJsonString(tenantMap, param);
//         map<string,Tenant>::const_iterator it = tenantMap.begin();
//         for(; it != tenantMap.end(); it++)
//         {
//             cout << "it->first: " << it->first << " " << endl;
//             cout << "ToJsonCompactString: " << ToJsonCompactString(it->second) << endl;
//             cout << "ToJsonString: " << ToJsonString(it->second) << endl;
//         }
//         // it->first: onesun
//         // it->first: twohu
//     }
// };
//
// // 解析
// TEST_F(Stop_FuxiJob_Test, GetSydStructFromParam)
// {
// LOG_INFO(logger, ("json_str call log info 并且测试中文: ", " no fields"));
// cout << "json_str is" << endl;
// GetSydStructFromParam(json_str);
// }
//
// TEST_F(Stop_FuxiJob_Test, GetTenantFromParam)
// {
// cout << "four_tenant is" << endl;
// GetTenantFromParam(four_tenant);
// }
//
